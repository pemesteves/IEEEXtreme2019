#include <iostream>
#include <vector>

using namespace std;

typedef long long int lli;

vector<lli> solution;
lli sol_size;

class Solution {
private:
    lli target, a, b;
    
public:
    Solution(lli t, lli a, lli b) {
        this->target = t;
        this->a = a;
        this->b = b;
    }
    
    bool find_sum(lli curr) {
        if(curr == target)
            return true;
            
        if (sol_size > 10e5+1) 
            return false;
            
        if(curr+a > target)
            return false;
            
        if(curr+a == target){
            solution[sol_size++] = a;
            return true;
        }
        
        for (lli c = b; c >= a; c--) {
            if(curr + c > target){
                //c = target - curr;
                continue;
            }

            solution[sol_size++] = c;
            
            if (sol_size > 10e5+1) 
                return false;
            
            if (find_sum(curr + c)) return true;
            sol_size--;
        }
        
        return false;
     }
};

int main() {
    lli n, a, b;
    cin >> n >> a >> b;
    
    solution.resize(10e5+1);
    sol_size = 0;
    
    if (a > n) {
        cout << "NO";
        return 0;
    }
    
    if(n >= a && n <= b){
        cout << "YES" << endl;
        cout << n << endl;
        return 0;
    }
    
    if (b > n) b = n;
    
    Solution sol(n, a, b);
    
    if (sol.find_sum(0)) {
        cout << "YES" << endl;
        for (int i = sol_size-1; i >= 0; i--)
            cout << solution[i] << " ";
    }
    else {
        cout << "NO";
    }
    
    return 0;
}