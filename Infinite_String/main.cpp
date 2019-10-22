#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int T; cin >> T;
    
    unsigned B;
    unsigned long long X;
    for (int t = 0; t < T; t++) {
        cin >> B >> X;
        unsigned j = 0;
        unsigned long long sum;
        unsigned long long p_value = 1;
        while(true){
            j++;
            p_value*=B;
            sum = p_value*j;
            if(sum <= X)
                X -= sum;
            else
                break;
        }   
        
        int set = X/j;
        int position_in_set = X%j;
        vector<char> chars(j, 'a');
        
        for(int i = 0; i < set; i++){
            chars[j-1]++;
            
            for(int k = j-1; k >= 0; k--){
                if(chars[k]-'a' >= B){
                    chars[k] = 'a';
                    chars[k-1]++;
                }   
            } 
        }
        
        cout << chars[position_in_set] << endl;
    }
    return 0;
}