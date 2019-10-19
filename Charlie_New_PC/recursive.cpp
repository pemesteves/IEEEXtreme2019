#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull find_best(vector<vector<ull>> & comps, int c, ull budget, ull best) {
    
    if(best > budget) return 0;
    
    if (c >= (int)comps.size()) return best; 
    
    ull max_found = 0;
    for (ull component : comps[c]) {
        max_found = max(find_best(comps, c+1, budget, best+component), max_found);
    }
    
    
    return max_found;
}


int main() {
    int T;
    cin >> T;
    
    ull budget;
    int N;
    for (int t = 0; t < T; t++) {
        cin >> budget >> N;
        
        int iter = 0;
        vector<int> options(N);
        for (int i = 0; i < N; i++)
            cin >> options[iter++];
        
        vector<vector<ull>> components(N);
        
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < options[i]; j++) {
                cin >> iter;
                components[i].push_back(iter);
            }
        }
        
        cout << find_best(components, 0, budget, 0) << endl;;
    }
    
    return 0;
}