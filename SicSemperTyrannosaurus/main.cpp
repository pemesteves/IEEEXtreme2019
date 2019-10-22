#include <iostream>
#include <vector>


using namespace std;

int main() {
    unsigned long int n, k, q;
    cin >> n >> k >> q;
    
    unsigned long int vi;
    vector<unsigned long int> v, v1;
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
            v1 = v;
            for(unsigned long int i = 0; i < k; i++){
                for(unsigned long int j = l; j < r; j++){
                    v1[j] += v1[j-1];
                }
            }
            cout << v1[r-1]%1000000007 << endl;
        }
        else{ //'U'
            cin >> p >> x;
            v[p-1] = x;
        }
        q--;
    }
    
    return 0;
}
       