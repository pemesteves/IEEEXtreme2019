#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n; 
    cin >> n;
    cin.clear();
    cin.ignore(10000, '\n');
    bool first_time = true;
    string input;
    int input_1 = 0, input_2 = 0;
    vector<int> v(2*n, 0);
    int option_1 = -1, option_2 = -1;
    istringstream iff;
    
    int blanck = -1;
    
    while(true){
        if(!first_time){
            getline(cin, input);
            if(input =="-1")
                return 0;
            if(input == "MATCH"){
                v[option_1-1] = -1;
                v[option_2-1] = -1;
            }
            else{
                iff.str(input);
                iff >> input_1 >> input_2;
                v[option_1-1] = input_1;
                v[option_2-1] = input_2;
            }
        }
        blanck = -1;
        option_1 = -1;
        option_2 = -1;
        for(size_t i = 0; i < v.size(); i++){
            if(v[i] == -1)
                continue;
            if(v[i] == 0 && blanck == -1){
                blanck = i; 
                continue;
            }
            else if (v[i] == 0){
                option_1 = blanck+1;
                option_2 = i+1;
                break;
            }
            
            for(size_t j = i+1; j < v.size(); j++){
                if(v[i] == v[j]){
                    option_1 = i+1;
                    option_2 = j+1;
                    break;
                }
            }
            if(option_1 != -1 && option_2 != -1)
                break;
        }
        
        cout << option_1 << " " << option_2 << endl;
        first_time = false;
    }
    
    return 0;
}