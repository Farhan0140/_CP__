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

/* 01 */ void pre_order (Node *root);
/* 02 */ void post_order (Node *root);
/* 03 */ void in_order (Node *root);
/* 04 */ void level_order (Node *root);
/* 05 */ Node *tree_input();
/* 06 */ int count_number_of_Nods (Node *root);
/* 07 */ int count_number_of_Leaf_Nods (Node *root);
/* 08 */ int Max_Height (Node *root);

//_______________________________________________________________________________________________


int main(){
    // Node *root = new Node(10); 
    // Node *a = new Node(20); 
    // Node *b = new Node(30); 
    // Node *c = new Node(40); 
    // Node *d = new Node(50); 
    // Node *e = new Node(60); 
    // Node *f = new Node(70); 
    // Node *g = new Node(80); 
    // Node *h = new Node(90); 
    // Node *i = new Node(100); 

    // Connection

    // root->left = a;
    // root->right = b;
    // a->left = c;
    // a->right = h;
    // c->right = e;
    // h->right = i;
    // b->right = d;
    // d->left = f;
    // d->right = g;

    Node *root = tree_input();

     pre_order(root); cout << endl;
    // pre_order(root); cout << endl;
    // in_order(root); cout << endl;
    // level_order(root);
    // cout << count_number_of_Nods(root) << endl;
    // cout << count_number_of_Leaf_Nods(root) << endl;
    // cout << Max_Height(root) << endl;

    return 0;
}


//_______________________________________________________________________________________________

/* 01 */ void pre_order (Node *root){

    if(root == NULL) { return; }

    cout << root->val << " ";

    pre_order(root->left);
    pre_order(root->right);
}

//_______________________________________________________________________________________________

/* 02 */ void post_order (Node *root) {
    if(root == NULL) { return; }

    post_order(root->left);
    post_order(root->right);

    cout << root->val << " ";
}

//_______________________________________________________________________________________________

/* 03 */ void in_order (Node *root) {
    if(root == NULL) { return; }

    in_order(root->left);
    cout << root->val << " ";
    in_order(root->right);
}

//_______________________________________________________________________________________________

/* 04 */ void level_order (Node *root) {
    if(root == NULL) {
        cout << "Tree is Empty" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front(); q.pop();

        cout << temp->val << " ";

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

//_______________________________________________________________________________________________

/* 05 */ Node *tree_input() {
    int val; cin >> val;

    Node *root;
    queue<Node *> q;

    if(val == -1) { root = NULL; return NULL; }
    else { root = new Node(val); q.push(root); }

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        int l, r; cin >> l >> r;
        Node *new_left, *new_right;

        if(l == -1) { new_left = NULL; }
        else { new_left = new Node(l); }

        if(r == -1) { new_right = NULL; }
        else { new_right = new Node(r); }

        temp->left = new_left;
        temp->right = new_right;

        if(temp->left) { q.push(temp->left); }
        if(temp->right) { q.push(temp->right); }
    }

    return root;
}

//_______________________________________________________________________________________________

/* 06 */ int count_number_of_Nods (Node *root) {
    if(root == NULL) { return 0; }

    int left_subTree = count_number_of_Nods(root->left);
    int right_subTree = count_number_of_Nods(root->right);

    return left_subTree + right_subTree + 1;
}

//_______________________________________________________________________________________________

/* 07 */ int count_number_of_Leaf_Nods (Node *root) {
    if(root == NULL) { return 0; }

    if(root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        int leftSubtree = count_number_of_Leaf_Nods(root->left);
        int rightSubtree = count_number_of_Leaf_Nods(root->right);

        return leftSubtree + rightSubtree;
    }
}

//_______________________________________________________________________________________________

/* 08 */ int Max_Height (Node *root) {
    if(root == NULL) { return 0; }

    int leftSubtree = Max_Height(root->left);
    int rightSubtree = Max_Height(root->right);

    return max(leftSubtree, rightSubtree) + 1;
}

//_______________________________________________________________________________________________