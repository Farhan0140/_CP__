#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

class Node{
    public:
        int val;
        Node *left;
        Node *right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

//_______________________________________________________________________________________________

/* 01*/ Node *Create_BST(vector<int> v, int l, int r);  // Using Sorted Array & Binary Search Technique
/* 02 */ bool Search_Value(Node *root, int n);
/* 03 */ void Insert(Node * &root, int x);

void InOrder(Node *root);

//*_______________________________________________________________________________________________


int main(){
    vector<int> v = {15,23,3,4,1,8,9,33,44,43,81,11,12,13};
    int l=0, r=v.size()-1;
    sort(v.begin(), v.end());
    Node *root = Create_BST(v, l, r);
    // InOrder(root);

    // if(Search_Value(root, 16)) { cout << "Found" << endl; }
    // else { cout << "Not Found" << endl; }

    Insert(root, 7);
    InOrder(root);
    return 0;
}


//!_______________________________________________________________________________________________

/* 01 */ Node *Create_BST(vector<int> v, int l, int r) {
    if(l > r) { return NULL; }

    int mid = (l+r)/2;

    Node *root = new Node(v[mid]);

    Node *LeftRoot = Create_BST(v, l, mid-1);
    Node *RightRoot = Create_BST(v, mid+1, r);

    root->left = LeftRoot;
    root->right = RightRoot;
    return root;
}

//!_______________________________________________________________________________________________

/* 02 */ bool Search_Value(Node *root, int n) {
    if(root == NULL) { return false; }
    if(root->val == n) { return true; }

    if(root->val > n) {
        return Search_Value(root->left, n);
    } else {
        return Search_Value(root->right, n);
    }
}

//!_______________________________________________________________________________________________

/* 03 */ void Insert(Node * &root, int x) {
    if(root == NULL) {
        root = new Node(x);
        return;
    }

    if(x < root->val) {
        if(root->left == NULL) {
            root->left = new Node(x);
        } else {
            Insert(root->left, x);
        }
    } else {
        if(root->right == NULL) {
            root->right = new Node(x);
        } else {
            Insert(root->right, x);
        }
    }
}

//_______________________________________________________________________________________________

void InOrder(Node *root) {
    if(root == NULL) { return; }

    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}

//_______________________________________________________________________________________________