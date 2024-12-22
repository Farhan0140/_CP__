#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

class Node{
    public:
      Node *previous;
      int data;
      Node *next;

    Node(int value){
        previous = NULL;
        data = value;
        next = NULL;
    }
};

//_______________________________________________________________________________________________

class Stack {
    public:
      Node *head = NULL;
      Node *tail = NULL;
      int size = 0;

    void Push(int val) {
        size++;
        Node *newNode = new Node(val);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    void Pop() {
        size--;
        Node *del = tail;
        tail = tail->previous;
        delete del;

        if(tail == NULL){
            head = NULL;
        }
    }

    int Top() {
        return tail->data;
    }

    int Size() {
        return size;
    }

    bool Empty() {
        if(size == 0) { return true; }
        else { return false; }
    }
};


//_______________________________________________________________________________________________


int main() {
    Stack st;
    int n;
    cout << "Enter the Size of Stack --> "; cin >> n;

    while(n--){
        int x; cin >> x;
        st.Push(x);
    }

    while(!st.Empty()) {
        cout << st.Top() << " ";
        st.Pop();
    }
    return 0;
}


//_______________________________________________________________________________________________