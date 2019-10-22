//Best submission to this exercise

#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

int main() {
    unsigned long int n, m;
    cin >> n >> m;
    
    list<unsigned long int> a;
    multiset<unsigned long int> sort_s;
    
    unsigned long int a_elem, s_elem;
    while(n > 0){
        cin >> a_elem;
        a.push_back(a_elem);
        n--;
    }
    
    while(m > 0){
        cin >> s_elem;
        sort_s.insert(s_elem);
        m--;
    }

    size_t i = 0;
    auto it1 = sort_s.begin();
    auto it = a.begin();
    for(it = a.begin(); it != a.end(); it++){
        if(it1 == sort_s.end())
            break;
        if(*it > *it1){
            a.insert(it, *it1);
            it1++;
            it--;
        }
    }
    
    while(it1 != sort_s.end()){
        a.insert(it, *it1);
        it1++;
    }

    for(it = a.begin(); it != a.end(); it++){
        cout << *it << " ";
    }
    
    return 0;
}