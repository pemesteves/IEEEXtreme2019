#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

typedef unsigned long ul;

int main() {
    ul N; cin >> N; 
    map<ul, pair<ul,ul>> cards;
    
    cerr << N << endl;
    
    string answer;
    ul r1, r2;
    for (ul i = 0; i < 2*N; i+=2) {
        cout << i+1 << " " << i+2 << endl;
        
        cin >> answer;
        
        if (answer == "MATCH") {
            continue;
        }
        
        istringstream iss(answer);
        iss >> r1;
        cin >> r2;
        
        
        map<ul, pair<ul,ul>>::iterator it1 = cards.find(r1);
        if(it1 == cards.end()) {
            cards[r1] = pair<ul,ul>(i+1, 0);
        }
        else {
            it1->second.second = i+1;
        }
        
        map<ul, pair<ul,ul>>::iterator it2 = cards.find(r2);
        if(it2 == cards.end()) {
            cards[r2] = pair<ul,ul>(i+2, 0);
        }
        else {
            it2->second.second = i+2;
        }
    }
    
    string match;
    for (auto iter = cards.begin(); iter != cards.end(); iter++) {
        cout << iter->second.first << " " << iter->second.second << endl;
        cin >> match;
    }
    
    cout << "-1" << endl;
    
    return 0;
}