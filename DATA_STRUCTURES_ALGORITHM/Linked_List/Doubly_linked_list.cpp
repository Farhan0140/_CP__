#include <bits/stdc++.h>
using namespace std;

//!---------------------------------------------------------------------------------------------

class Node{
    public:
        Node *prev;  //        |-----------|----------|-----------|
        int data;    //        | PREVIOUS  |   DATA   |   NEXT    |
        Node *next;  //        |___________|__________|___________|
};                   //                        NODE

Node *head = NULL;
Node *tail = NULL;

//!---------------------------------------------------------------------------------------------

void Create_Doubly_Linked_List(int A[], int size);
void Push_Front(int value);
void Push_Back(int value);
void Insert_H_T(int value, int index);  // Head to Tail
void Insert_T_H(int value, int index);  // Tail to Head
bool Search_H_T(int value);     // searching Head to Tail
bool Search_T_H(int value);     // searching Tail to Head
void Pop_Front();   // deleting First value
void Pop_Back();    // deleting Last value
void Delete_Node(int value);    // Delete any Node expect First ans last
void Sort_A();    // sort in ascending order

void Print_Forward();
void Print_Backward();

//!_____________________________________________________________________________________________

int main(){
    int arr[] = {10,1,2,3,4,5,6,7,89,0,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    Create_Doubly_Linked_List(arr, len);

    // Push_Back(56);
    // Push_Front(404);

    // Insert_H_T(505, 98);
    // Insert_T_H(1000, 2);

    // bool bl = Search_H_T(505);
    // bool bl = Search_T_H(89);
    // if(bl == true){ cout << "FOUND" << endl; }
    // else{ cout << "NOT FOUND" << endl; }
    
    // Pop_Front();
    // Pop_Back();
    // Delete_Node(89);
    // Delete_Node(2);

    Sort_A();
    Print_Forward();
    Print_Backward();
    return 0;
}

//!---------------------------------------------------------------------------------------------

void Create_Doubly_Linked_List(int A[], int size){
    for(int i=0; i<size; i++){
        Node *temp = new Node();
        Node *current = head;
        if(head == NULL){
            temp->data = A[i];
            temp->next = temp->prev = NULL;
            head = tail = temp;
        }else{
            while(current->next != NULL){ current = current->next; }
            temp->data = A[i];
            temp->prev = current;
            temp->next = NULL;
            current->next = temp;
            tail = temp;
        }
    }
}

//!_____________________________________________________________________________________________

void Push_Front(int value){
    Node *temp = new Node();
    if(head == NULL){
        temp->data = value;
        temp->next = temp->prev = NULL;
        head = temp;
        tail = temp;
    }else{
        temp->data = value;
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

//!_____________________________________________________________________________________________

void Push_Back(int value){
    Node *temp = new Node();
    Node *current = head;
    if(head == NULL){
        temp->data = value;
        temp->next = temp->prev = NULL;
        head = tail = temp;
    }else{
        while(current->next != NULL){ current = current->next; }
        temp->data = value;
        temp->prev = current;
        temp->next = NULL;
        current->next = temp;
        tail = temp;
    }
}

//!_____________________________________________________________________________________________

void Insert_H_T(int value, int index){
    Node *temp = new Node();
    Node *current = head;
    int count = 1;
    while(current != NULL){
        count++;
        if(count == index){ break; }
        current = current->next;
    }
    temp->data = value;
    temp->next = current->next;
    temp->prev = current;
    current->next->prev = temp;
    current->next = temp;
}

//!_____________________________________________________________________________________________

void Insert_T_H(int value, int index){
    Node *temp = new Node();
    Node *current = tail;
    int count = 1;
    while(current != NULL){
        count++;
        if(count == index){ break; }
        current = current->prev;
    }
    temp->data = value;
    temp->prev = current->prev;
    temp->next = current;
    current->prev->next = temp;
    current->prev = temp;
}

//!_____________________________________________________________________________________________

bool Search_H_T(int value){
    Node *temp = head;
    while(temp != NULL){
        if(temp->data == value){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//!_____________________________________________________________________________________________

bool Search_T_H(int value){
    Node *temp = tail;
    while(temp != NULL){
        if(temp->data == value){
            return true;
        }
        temp = temp->prev;
    }
    return false;
}

//!_____________________________________________________________________________________________

void Pop_Front(){
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

//!_____________________________________________________________________________________________

void Pop_Back(){
    Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
}

//!_____________________________________________________________________________________________

void Delete_Node(int value){
    if(head == NULL){
        cout << "List Not Found" << endl;
    }else{
        Node *current = head;
        Node *temp = new Node();
        Node *previous = new Node();

        while(current->data != value){
            previous = current;
            current = current->next;
        }

        temp = current->next;
        previous->next = temp;
        temp->prev = previous;
        free(temp);
    }
}

//!_____________________________________________________________________________________________

void Sort_A(){
    if(head == NULL){
        cout << "List Not Found" << endl;
    }else{
        Node *previous = head;
        Node *current = new Node();

        while(previous != NULL){
            current = previous->next;
            
            while(current != NULL){
                if(current->data < previous->data){
                    swap(current->data, previous->data);
                }
                current = current->next;
            }
            previous = previous->next;
        }
    }
}

//!_____________________________________________________________________________________________

void Print_Forward(){
    Node *current = head;
    while(current != NULL){
        cout << "[" << current->data << "]-->";
        current = current->next;
    }
    cout << "[TAIL]" << endl;
}

//!---------------------------------------------------------------------------------------------

void Print_Backward(){
    Node *current = tail;
    while(current != NULL){
        cout << "[" << current->data << "]-->";
        current = current->prev;
    }
    cout << "[HEAD]" << endl;
}

//!---------------------------------------------------------------------------------------------