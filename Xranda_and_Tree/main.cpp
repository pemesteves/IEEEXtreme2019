#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef unsigned long long ull;

struct Edge;

struct Node {
    ull id;
    Node * parent;
    ull parent_label;
    vector<Edge> edges;
};

struct Edge {

    Node * dest;
    ull label;
    Edge(Node* d, ull l) {
        dest = d;
        label = l;
    }
};

ull N;
vector<vector<ull>> calculated_labels;

void assign_labels(Node * src, Node * dest) {
    if(src->id == dest->id) return;
    
    ull max_found = 0;
    for(Node * iter = src; iter->id != dest->id; iter = iter->parent) {
        max_found = max(max_found, iter->parent_label);
        calculated_labels[iter->id][src->id] = max_found;
        calculated_labels[src->id][iter->id] = max_found;
        
        assign_labels(iter->parent, dest);
        
        //cout << "assigned " << iter->id+1 << " to " << src->id+1 << endl;
    }
    calculated_labels[dest->id][src->id] = max_found;
    calculated_labels[src->id][dest->id] = max_found;
        
    //cout << "assigned " << dest->id+1 << " to " << src->id+1 << endl;
}

ull max_label(Node * n1, Node * n2) {
    
    vector<bool> visited(N, false);
    
    stack<Node*> to_visit;
    to_visit.push(n1);
    
    Node * last_node = n2;
    ull precalc_label = 0;
    
    while(!to_visit.empty()) {
        Node * next = to_visit.top();
        to_visit.pop();
        visited[next->id] = true;
        if (next->id == n2->id) break;
        
        for (unsigned int i = 0; i < next->edges.size(); i++) {
            Node * edge_dest = next->edges[i].dest;
            
            // prevent loops
            if(visited[edge_dest->id]) continue;
            
            edge_dest->parent = next;
            edge_dest->parent_label = next->edges[i].label;
            
            // already calculated
            if (calculated_labels[edge_dest->id][n2->id]) {
                last_node = edge_dest;
                precalc_label = calculated_labels[edge_dest->id][n2->id];
                break;
            }
            
            to_visit.push(edge_dest);
        }
    }
    
    // found precalc during dfs
    if (last_node->id != n2->id) {
        assign_labels(last_node, n1);
        
        calculated_labels[n2->id][n1->id] = max(precalc_label, calculated_labels[last_node->id][n1->id]);
        calculated_labels[n1->id][n2->id] = max(precalc_label, calculated_labels[last_node->id][n1->id]);
    }
    else {
        assign_labels(n2, n1);
    }
    
    //cout << "calling assign from " << n1->id+1 << " to " << n2->id+1 << endl;
    
    return calculated_labels[n1->id][n2->id];
}

int main() {
    cin >> N;
    
    for(ull i = 0; i < N; i++) 
        calculated_labels.push_back(vector<ull>(N, 0));
    
    vector<Node> nodes(N);
    
    ull e1, e2, label;
    for (ull i = 0; i < N-1; i++) {
        cin >> e1 >> e2 >> label;
        
        nodes[i].id = i;
        nodes[e1-1].edges.push_back(Edge(&nodes[e2-1], label));
        nodes[e2-1].edges.push_back(Edge(&nodes[e1-1], label));
        
    }
    nodes[N-1].id = N-1;
    
    ull total = 0;
    for (ull i = 0; i < N; i++) {
        for (ull j = N-1; j > i; j--) {
            ull curr_label;
            
            if (calculated_labels[i][j]) {
                curr_label = calculated_labels[i][j];
                //cout << "pre " << i+1 << " to " << j+1 << endl;
            }
            else {
                curr_label = max_label(&nodes[i], &nodes[j]);
                //cout << "calculated " << i+1 << " to " << j+1 << endl;
            }
            
            total += curr_label;
        }
    }
    
    cout << total;
    
    return 0;
}