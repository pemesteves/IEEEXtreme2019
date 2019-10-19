#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <math.h>
#include <algorithm>

using namespace std;

typedef unsigned int ui; 


ui gcd_func(ui a, ui b) 
{ 
    if (b == 0) 
        return a; 

    return gcd_func(b, a % b);  
      
} 

void generate_all_subsequences(const vector<ui> sequence, vector<vector<ui>> &subsequences)
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
         subsequences.push_back(move(candidate));
    }
}

int main() {
    ui n, k;
    cin >> n >> k;
    vector<ui> a;
    ui a_elem;
    
    ui i = 0; 
    unordered_set<int> results;
    //vector<int> results;
    
    while(i < n){
        cin >> a_elem;
        a.push_back(a_elem);
        
        if(results.find(a_elem) == results.end()){ 
            results.insert(a_elem);
        }

        i++;
    }
    vector<vector<ui>> vli;
    generate_all_subsequences(a, vli);
 
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