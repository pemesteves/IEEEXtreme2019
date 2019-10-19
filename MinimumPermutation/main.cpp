#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    unsigned int n, m;
    cin >> n >> m;
    
    vector<unsigned int> a;
    set<unsigned int> sort_s;
    
    unsigned int a_elem, s_elem;
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
    vector<unsigned int> result;
    
    for(auto it : sort_s){
        if(i >= a.size()){
            result.push_back(it);
            continue;
        }
        for(; i < a.size(); i++){
            if(it < a[i]){
                result.push_back(it);
                break;
            }   
            result.push_back(a[i]);
        }
    }
    
    for(; i < a.size(); i++){
        result.push_back(a[i]);
    }
    
    for(i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    
    return 0;
}