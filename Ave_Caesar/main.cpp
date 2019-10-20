#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long ul;

bool isValidString(string s) {
    
    vector<string> substrings;
    ul start_i = 0;
    char prev = s[start_i];
    for (ul i = 1; i < s.size(); i++) {
        if (s[i] >= prev) {
            prev = s[i];
        }
        else {
            
            substrings.push_back(s.substr(start_i, i-start_i));
            prev = s[i];
            start_i = i;
        }
    }
    substrings.push_back(s.substr(start_i));
    
    for (ul i = 0; i < substrings.size()-1; i++) {
        if (substrings[i] > substrings[i+1])
            return false;
    }
    
    return true;
}

int main() {
    ul N; cin >> N;
    
    string s;
    for (ul i = 0; i < N; i++) {
        cin >> s;
        
        cout << (isValidString(s) ? 1 : 0);
    }
    
    return 0;
}