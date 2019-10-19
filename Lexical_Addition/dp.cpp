#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long int n, a, b;
    cin >> n >> a >> b;
    
    long long int size = n+1;    
    vector<long long int> prev(size, -1);
    vector<long long int> solution_size(size, 0);
    
    long long int lower = a, upper = b;
    if (a > n) upper = a-1;
    if (b > n) upper = n;
    
    for (long long int curr = lower; curr <= upper; curr++) {
        
        for (long long int target = 1; target < size; target++) {
            
            if((target - curr) < 0) continue;
            
            if(curr == target) {
                solution_size[target] = 1;
                prev[target] = curr;
                continue;
            }
            
            // if there is a new option
            if (prev[target - curr] != -1) {
                    
                    // current solution is better
                    if (prev[target] != -1 && solution_size[target] < (solution_size[target-curr]+1)) continue;
                    
                    prev[target] = curr;
                    solution_size[target] = solution_size[target-curr]+1;
            }
            
        }
    }
    
    if (prev[n] != -1) {
        cout << "YES" << endl;
        vector<long long int> sol;
        long long int num = n;
        while(num > 0 && prev[num] != -1) {
            sol.push_back(prev[num]);
            num -= prev[num];
        }
        
        for (long long int i = sol.size()-1; i >= 0; i--) cout << sol[i] << " ";
    }
    else {
        cout << "NO";
    }
    
    return 0;
}