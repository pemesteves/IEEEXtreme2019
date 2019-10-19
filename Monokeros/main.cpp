#include <iostream>

using namespace std;

typedef long long int lli;

struct Node {
    Node * left;
    Node * right;
    lli value;
    Node(lli v) {
        left = nullptr;
        right = nullptr;
        value = v;
    }
};

void insert_node(Node * curr, lli val, lli depth) {
    if (val <= curr->value) {
        if (curr->left == nullptr) {
            curr->left = new Node(val);
            cout << depth+1 << " ";
        }
        else {
            insert_node(curr->left, val, depth+1);
        }
    }
    else {
        if (curr->right == nullptr) {
            curr->right = new Node(val);
            cout << depth+1 << " ";
        }
        else {
            insert_node(curr->right, val, depth+1);
        }
    }
}

int main() {
    int N; cin >> N;
    
    lli v; cin >> v;
    Node head = Node(v);
    cout << "1 ";
    
    for (int i = 1; i < N; i++) {
        cin >> v;
        insert_node(&head, v, 1);
    }
    
    
    
}