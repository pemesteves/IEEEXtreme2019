#include <iostream>
#include <math.h>

using namespace std;

typedef unsigned long long int ull;

int main() {
    int T; cin >> T;
    
    ull B, X;
    for (int t = 0; t < T; t++) {
        cin >> B >> X;
        
        ull mult = B;
        int power = 2;
        while(mult <= X) {
            mult += pow(B, power);
            power++;
        }
        
        int last_power_used = power-1;
        
        string res = "";
        
        while(X >= B) {
            ull rest = mult - pow(B, last_power_used);
            ull div = (mult - rest) / pow(B, last_power_used-1);
            res += ('a' + div);
            
            X -= pow(B, last_power_used-1);
            mult = rest;
            last_power_used--;
        }
        
        res += ('a' + X);
        
        cout << res << endl;
    }
}