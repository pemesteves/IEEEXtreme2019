#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <algorithm>

using namespace std;

typedef unsigned int ui; 

ui gcd_func(ui &x, ui &y) {
	ui temp;
	while (y != 0) {
		temp = y;
		y = x % y;
		x = temp;
	}
	
    return x;
}

void generate_all_subsequences(const vector<ui> &sequence, vector<vector<ui>> &subsequences)
{
    const int n = sequence.size();

    int num = pow(2, n);

    for (int i = 0; i <= num - 1; i++) {
        vector<ui> candidate;
        for (int j = 0; j <= n - 1; j++) {
            if (((i >> j) & 1) == 1) {
                candidate.push_back(sequence[j]);
            }
         }
         
         if(candidate.size() == 0 || candidate.size() == 1 || candidate.size() >2)// sequence.size())
            continue;
         subsequences.push_back(move(candidate));
    }
}

int main() {
    ui n, k;
    cin >> n >> k;
    vector<ui> a;
    ui a_elem;
    
    set<int> results;
    
    for(ui i = 0; i < n; i++){
        cin >> a_elem;
        a.push_back(a_elem);
        
        if(results.find(a_elem) == results.end()){ 
            results.insert(a_elem);
        }
    }
    vector<vector<ui>> vli;
    generate_all_subsequences(a, vli);
    a.clear();
    
    for(size_t i = 0; i < vli.size(); i++){

        if(vli[i].size() <= 1 || vli[i].size() > k)
            continue;
    
        ui gcd = vli[i][0];
        
        for(size_t j = 1; j < vli[i].size(); j++){
            ui new_gcd = gcd_func(gcd, vli[i][j]);
            
            gcd = new_gcd;
        }
        if(results.find(gcd) == results.end()){ 
            results.insert(gcd);
        }
    }
    
    
    cout << results.size();
    return 0;
}