#include<bits/stdc++.h>
using namespace std;

#define ll int
#define I_HATE_PROGRAMMING int main
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//---------------------------------------------------------------------

class Node{
    public:                //  |--------|--------|
        int data;          //  |  Data  |  Next  |
        Node *next;        //  |________|________|
};                         //          NODE

Node *head = NULL;

//---------------------------------------------------------------------
/* 1 */void Create_Linked_List(ll A[], ll size);
/* 2 */bool search_linked_list(int value);
/* 3 */void Push_Front(ll value);
/* 4 */void Push_Back(ll value);
/* 5 */void Insert(ll index, ll value);
// * Insert a Node in a specific order in a linked list
/* 6 */void Insert_S(ll value);
/* 7 */void Pop_Front();                // Pop = Delete
/* 8 */void Pop_Back();  
/* 9 */void Delete(ll value);   // Delete any position
/* 10 */void reverse_linked_list();
/* 11 */void Sort_A();    // sort in ascending order
/* 12 */void Sort_D();    // sort in descending order
/* 13 */void Size();    // finding how many nodes are in list
//---------------------------------------------------------------------

void print();

//---------------------------------------------------------------------


I_HATE_PROGRAMMING(){
    fast_read();

    int arr[] = {10,1,2,3,9,4,5,6,7,89,0,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    Create_Linked_List(arr, len);

    //reverse_linked_list();
    //Sort_D();
    Size();

    print();
    return 0;
}


//! 1 //----------------------------------------------------------------

void Create_Linked_List(ll A[], ll size){
    for(int i=0; i<size; i++){
        if(head == NULL){
            Node *newNode = new Node();
            newNode->data = A[i];
            newNode->next = NULL;
            head = newNode;
        }else{
            Node *current = new Node();
            current = head;

            while(current->next != NULL){
                current = current->next;
            }

            Node *temp = new Node();
            temp->data = A[i];
            temp->next = NULL;

            current->next = temp;
        }
    }
}

//! 2 //----------------------------------------------------------------

bool search_linked_list(int value){
    Node *temp = head;
    while(temp != NULL){
        if(temp->data == value){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//! 3 //----------------------------------------------------------------

void Push_Front(ll value){
    Node *temp = new Node();

    temp->data = value;
    temp->next = head;

    head = temp;
}

//! 4 //----------------------------------------------------------------

void Push_Back(ll value){
    Node *current = head;
    while(current->next != NULL){
        current = current->next;
    }

    Node *temp = new Node();
    temp->data = value;
    temp->next = NULL;

    current->next = temp;
}

//! 5 //----------------------------------------------------------------

void Insert(ll index, ll value){
    Node *current = head;
    ll cnt=1;
    while(current != NULL){
        cnt++;
        if(cnt == index){
            Node *temp = new Node();
            temp->data = value;
            temp->next = current->next;
            current->next = temp;
            break;
        }
        current = current->next;
    }
}

//! 6 //----------------------------------------------------------------

// * Insert a Node in a specific order in a linked list

void Insert_S(ll value){
    Node *current = head;
    while(current->next->data < value){
        current = current->next;
    }

    Node *temp = new Node();
    temp->data = value;
    temp->next = NULL;

    temp->next = current->next;
    current->next = temp; 
}

//! 7 //----------------------------------------------------------------

void Pop_Front(){
    Node *temp = head;

    head = head->next;
    free(temp);
}

//! 8 //----------------------------------------------------------------

void Pop_Back(){
    Node *current = head;

    if(head == NULL){
        exit(0);
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
    }else{
        while(current->next->next != NULL){
            current = current->next;
        }
        
        Node *temp = current->next;
        current->next = NULL;
        free(temp);
    }
}

//! 9 //----------------------------------------------------------------

void Delete(ll value){
    Node *current = head;
    Node *temp;
    while(current->data != value){
        temp = current;
        current = current->next;
    }

    temp->next = current->next;
    free(current);
}

//! 10 //----------------------------------------------------------------

void reverse_linked_list(){
    Node *previous=NULL, *current=head, *n=NULL; // n = Next
    while(current != NULL){
        n = current->next;
        current->next = previous;
        previous = current;
        current = n;
    }
    head = previous;
}

//! 11 //----------------------------------------------------------------

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

//! 12 //----------------------------------------------------------------

void Sort_D(){
    if(head == NULL){
        cout << "List Not Found" << endl;
    }else{
        Node *previous = head;
        Node *current = new Node();

        while(previous != NULL){
            current = previous->next;
            
            while(current != NULL){
                if(current->data > previous->data){
                    swap(current->data, previous->data);
                }
                current = current->next;
            }
            previous = previous->next;
        }
    }
}

//! 13 //----------------------------------------------------------------

void Size(){
    int count = 0;
    if(head == NULL){
        cout << "Total Node is : 0" << endl;
    }else{
        Node *temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        cout << "Total Node is : " << count << endl;
    }
}

// ? //----------------------------------------------------------------

//----------------------------------------------------------------------
void print(){
    Node *current = head;

    while(current != NULL){
        cout << "[" << current->data << "]-->";
        // cout << "[" << current->data << "][" << current << "]--> "; // current print the address
        current = current->next;
    }
    cout << "[NULL]" << endl;
}
//----------------------------------------------------------------------