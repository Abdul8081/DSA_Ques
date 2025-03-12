#include<bits/stdc++.h>
using namespace std;
#define im INT_MIN
class Node { // TreeNode 
public:
    Node* left;
    Node* right;
    int val;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(vector<int> arr) {
    //construction of the tree, bfs way
    int n = arr.size();
    Node* root = new Node(arr[0]);
    int i = 1;
    int j = 2;
    queue<Node*> q;
    q.push(root);
    while (q.size() and i<n){
        Node* temp = q.front();
        q.pop();
        Node *l,*r;
        if(arr[i]!=im) l = new Node(arr[i]);
        else l = nullptr;

        if(j!=n and arr[j]!=im) r = new Node(arr[j]);
        else r = nullptr;

        temp->left = l;
        temp->right = r;
        if(l) q.push(l);
        if(r) q.push(r);
        i+=2;
        j+=2;
    }
    return root;
}

void topView(Node* root) {
    unordered_map<int, int> mp; // level, value
    queue<pair<Node*,int> > q; // Node, level
    pair<Node*,int> r; // Node, level, Helping Queue Operation

    r.first = root;
    r.second = 0;
    q.push(r);

    while(q.size()) {
        Node* temp = q.front().first;
        int level = q.front().second;
        q.pop();

        if(!(mp.count(level))) mp[level] = temp->val;

        if(temp->left) {
            pair<Node*, int> p;
            p.first = temp->left;
            p.second = level -1;
            q.push(p);
        }
        if(temp->right) {
            pair<Node*, int> p;
            p.first = temp->right;
            p.second = level+1;
            q.push(p);
        }
    }

    //printing the top view
    int minLevel = INT_MAX;
    int maxLevel = im;
    for(auto x : mp) {
        int level = x.first;
        minLevel = min(minLevel, level);
        maxLevel = max(maxLevel, level);
    }

    for(int i=minLevel; i<=maxLevel; i++) {
        cout<<mp[i]<<" ";
    }
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 60, 90, 100};
    Node* root = construct(arr);
    topView(root); // doing level order traversal
}