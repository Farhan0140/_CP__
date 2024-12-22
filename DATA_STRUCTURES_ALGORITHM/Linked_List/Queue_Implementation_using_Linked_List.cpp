#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

class Node{
    public:
      int data;
      Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

//_______________________________________________________________________________________________

class Queue{
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
            tail = newNode;
        }
    }

    void Pop() {
        size--;
        Node *del = head;
        head = head->next;
        delete del;

        if(head == NULL){
            tail = NULL;
        }
    }

    int Front() {
        return head->data;
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
    Queue q;
    int n;
    cout << "Enter the Size of Queue --> "; cin >> n;

    while(n--){
        int x; cin >> x;
        q.Push(x);
    }

    while(!q.Empty()) {
        cout << q.Front() << " ";
        q.Pop();
    }
    return 0;
}


//_______________________________________________________________________________________________