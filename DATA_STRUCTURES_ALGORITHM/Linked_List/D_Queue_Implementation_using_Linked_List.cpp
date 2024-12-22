#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *Left = NULL;
Node *Right = NULL;

//_______________________________________________________________________________________________

void left_enqueue(int value);
void right_enqueue(int value);
int left_dequeue();
int right_dequeue();
int left();
int right();
void Print();

//_______________________________________________________________________________________________


int main(){
    cout << "After some Left-enqueue: ";
    left_enqueue(11);
    left_enqueue(22);
    left_enqueue(33);
    left_enqueue(44);
    Print();

    cout << "After some Right-enqueue: ";
    right_enqueue(100);
    right_enqueue(200);
    right_enqueue(300);
    right_enqueue(400);
    right_enqueue(500);
    Print();

    cout << "Left-D_Queue: " << left_dequeue() << endl;
    cout << "Left-D_Queue: " << left_dequeue() << endl;
    cout << "After left d_queue: "; Print();

    cout << "Right-D_Queue: " << right_dequeue() << endl;
    cout << "Right-D_Queue: " << right_dequeue() << endl;
    cout << "After Right d_queue: "; Print();

    cout << "Top Left value: " << left() << endl;
    cout << "Top Right value: " << right() << endl;
    return 0;
}


//_______________________________________________________________________________________________

void left_enqueue(int value){

    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL){ cout << "D_Queue Overflow!..." << endl; exit(1); }

    new_node->data = value;
    new_node->next = NULL;

    if(Left == NULL && Right == NULL){
        Left = new_node;
        Right = new_node;
    } else if(Left == NULL){
        Left = new_node;
    } else {
        new_node->next = Left;
        Left = new_node;
    }
}


void right_enqueue(int value){
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL){ cout << "D_Queue Overflow!..." << endl; exit(1); }

    new_node->data = value;
    new_node->next = NULL;

    if(Left == NULL && Right == NULL){
        Left = new_node;
        Right = new_node;
    } else if(Right == NULL){
        Right = new_node;
    } else {
        Right->next = new_node;
        Right = new_node;
    }
}


int left_dequeue(){
    if(Left == NULL){
        cout << "D_Queue is empty..." << endl;
        exit(1);
    }

    Node *temp = Left;
    Left = Left->next;

    return temp->data;
}


int right_dequeue(){
    if(Left == NULL){
        cout << "D_Queue is empty..." << endl;
        exit(1);
    }

    Node *current = Left;

    while(current->next->next != NULL){
        current = current->next;
    }

    Node *temp = current->next;
    current->next = NULL;
    Right = current;

    return temp->data;
}


int left(){
    if(Left == NULL){ cout << "D_Queue is empty.." << endl; exit(1); }
    return Left->data;
}


int right(){
    if(Right == NULL){ cout << "D_Queue is empty.." << endl; exit(1); }
    return Right->data;
}


void Print(){
    Node *current = Left;

    while(current != NULL){
        cout << "[" << current->data << "] ";
        current = current->next;
    }
    cout << endl;
}

//_______________________________________________________________________________________________