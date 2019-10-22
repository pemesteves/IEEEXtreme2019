//As our name says, we choose brute force for this task

#include <iostream>
#include <random>

using namespace std;

int main() {
    int N; cin >> N;
    
    string res;
    
    for (int i = 0; i < N; i++) {
        
        
        if ((3*rand())  % 2 == 0 && (5*rand()) % 2 == 0)
            res += 'Y';
        else
            res += 'y';
    }
    
    cout << res;
    
    
    return 0;
}