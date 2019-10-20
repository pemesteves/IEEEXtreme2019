#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long int lli;

//vector<lli> solution;
map<lli, lli> count;
//lli sol_size;

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
            
        /*if(curr > target)
            return false;*/
            
        if(curr+a > target)
            return false;
            
        if(curr+a == target){
            count[a]++;
            return true;
        }
        
        for (lli c = b; c >= a; c--) {
            if(curr + c > target){
                //c = target - curr;
                continue;
            }

            //solution[sol_size++] = c;
            count[c]++;
            if (find_sum(curr + c)) return true;
            count[c]--;
        }
        
        return false;
     }
};

int main() {
    lli n, a, b;
    cin >> n >> a >> b;
    
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
        for (auto iter = count.begin(); iter != count.end(); iter++) {
            for (int c = 0; c < iter->second; c++)
                cout << iter->first << " ";
        }
    }
    else {
        cout << "NO";
    }
    
    return 0;
}