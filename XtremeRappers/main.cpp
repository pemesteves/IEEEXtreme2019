#include <iostream>

using namespace std;

int main() {
    unsigned long long a, b;
    cin >> a >> b;
    
    unsigned long long max = 0;
    
    if(a == b){
        max = 2*a/3;
    }
    else if (a % 3 == 0 && b % 3 == 0){
        a /= 3;
        b /= 3;
        
        while(a != 0 && b != 0 && a + b >= 2){
           if(a < b){
                a--;
                b -= 2;
            }
            else{
                a -= 2;
                b--;
            }
            max++;
        }
        
        max *= 3;
    }
    else if(2*a < b){
        max = a;
    }
    else if (2*b < a){
        max = b;
    }
    else{
        while(a != 0 && b != 0 && a + b > 2){
           if(a < b){
                a--;
                b -= 2;
            }
            else{
                a -= 2;
                b--;
            }
            max++;
        }
    }
    
    cout << max;
    
    return 0;
}