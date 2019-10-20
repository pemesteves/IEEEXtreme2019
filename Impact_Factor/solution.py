import json

class Publication:
    def __init__(self, title, number, publications):
        self.title = title
        self.number = number
        self.publications = publications
        self.citations = 0
    

def getline():
    return input()
    
def valid_year(year):
    return year == "2018" or year == "2017"

n = int(getline())

header_info = json.loads(getline())

publications = {}
for publ in header_info['publications']:
    title = publ['publicationTitle']
    num = publ['publicationNumber']
    artCounts = publ['articleCounts']
    
    total = 0
    for item in artCounts:
        if valid_year(item["year"]):
            total += int(item["articleCount"])
            
    publications[num] = Publication(title, num, total)
    
for i in range(n-1):
    line = json.loads(getline())
    
    for citation in line["paperCitations"]["ieee"]:
        if citation["publicationNumber"] in publications and valid_year(citation["year"]):
            publications[citation["publicationNumber"]].citations += 1

solution = []
for publ_n in publications:
    p = publications[publ_n]
    div = p.citations * 1.0 / p.publications
    solution.append({"title": p.title, "num": round(div,2)})
    #print("{}: {:.2f}".format(p.title, round(div, 2)))
    
solution.sort(key=lambda x: x["num"], reverse=True)

for sol in solution:
    print("{}: {:.2f}".format(sol["title"], sol["num"]))
    

    