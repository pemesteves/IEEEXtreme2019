#include <iostream>

using namespace std;

typedef long long int lli;

int scenarios = 0;

void calc_scenarios(lli target, lli curr, lli prev) {
    
    if (curr > target) return;
    
    if (curr == target) {
        scenarios++;
        return;
    }
    
    if (prev == -1) {
        calc_scenarios(target, curr+1, 2);
    }
    else {
        calc_scenarios(target, curr+prev, prev * 2);
        calc_scenarios(target, curr, -1);
    }
}

int main() {
    lli N; cin >> N;
    
    lli points;
    for(int i = 0; i < N; i++) {
        scenarios = 0;
        cin >> points;
        
        calc_scenarios(points, 0, 1);
        
        cout << scenarios << endl;
    }
    
    return 0;
}