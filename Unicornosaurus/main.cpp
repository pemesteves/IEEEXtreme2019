#include <iostream>
#include <vector>

using namespace std;

typedef long long int lli;

struct Segment {
    lli start, end;
    Segment(lli s, lli e) { start = s; end = e; }
};

struct Superpower {
    lli start, end, cost;
    Superpower(lli s, lli e, lli c) {
        start = s;
        end = e;
        cost = c;
    }
};

int main() {
    int N, M, n_planks;
    cin >> N >> M >> n_planks;
    
    
    vector<Segment> broken_segments;
    int Li, Ri;
    for (int i = 0; i < N; i++) {
        cin >> Li >> Ri;
        broken_segments.push_back(Segment(Li, Ri));
    }
    
    vector<Superpower> actions;
    int Ai, Bi, Ci;
    for (int i = 0; i < M; i++) {
        cin >> Ai >> Bi >> Ci;
        actions.push_back(Superpower(Ai, Bi, Ci));
    }
    
    vector<bool> planks(n_planks, true);
    
    for(int i = 0; i < broken_segments.size(); i++) {
        
    }
    
    
}