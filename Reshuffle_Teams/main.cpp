#include <iostream>
#include<bits/stdc++.h> 
#include <unordered_map>

using namespace std;

typedef unsigned long int uli;



unordered_map<char, int> priority;
int main() {
    int T; cin >> T;
    
    for (int i = 0; i < T; i++) {
        priority.clear();
        
        string inp;
        cin >> inp;
        
        int next = 0;
        for (char & c : inp) {
            if (priority.find(c) == priority.end()) {
                priority[c] = next++;
            }
        }
        
        string sorted = inp;
        sort(sorted.begin(), sorted.end(), [](char a, char b) {
            return priority[a] < priority[b];
        });
        
        char first_char = inp[0];
        
        int inp_start = inp.find_first_of(first_char);
        uli iters = 0;
        while(iters < inp.length() && inp[inp_start] == first_char) {
            inp_start -= 1;
            if (inp_start < 0) inp_start += inp.length();
            iters++;
            
        }
        inp_start = (inp_start + 1) % inp.length();
        
        int sorted_start = sorted.find_first_of(first_char);
        
        //cout << inp << " - " << sorted << endl;
        //cout << inp_start << " - " << sorted_start;
        
        uli wrong = 0;
        for (unsigned int i = 0; i < inp.length(); i++) {
            
            if (inp[inp_start] != sorted[sorted_start])
                wrong++;
            
            inp_start = (inp_start+1) % inp.length();
            sorted_start = (sorted_start+1) % sorted.length();
            
        }
        
        cout << wrong << endl;
    }
    
    return 0;
}