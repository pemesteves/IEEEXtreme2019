#include <iostream>
#include <vector>


using namespace std;

int main() {
    unsigned long int n, k, q;
    cin >> n >> k >> q;
    
    unsigned long int vi;
    vector<unsigned long int> v;
    while(n > 0){
        cin >> vi;
        v.push_back(vi);
        n--;
    }
    char beginning;
    unsigned long int l, r, p, x; 
    while(q > 0){
        cin >> beginning;
        if(beginning == 'Q'){
            cin >> l >> r;
            
            for(unsigned long int i = 0; i < k; i++){
                for(unsigned long int j = l; j < r; j++){
                    v[j] += v[j-1];
                }
            }
            cout << v[r-1]%1000000007 << endl;
            for(unsigned long int i = 0; i < k; i++){
                for(unsigned long int j = r-1; j >= l; j--){
                    v[j] -= v[j-1];
                }
            }
        }
        else{ //'U'
            cin >> p >> x;
            v[p-1] = x;
        }
        q--;
    }
    
    return 0;
}
       