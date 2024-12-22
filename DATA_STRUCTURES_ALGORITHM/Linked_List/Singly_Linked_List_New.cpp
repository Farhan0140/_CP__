//TODO Use Vs code [Better Comments] Extension

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define tc int ttc; cin >> ttc; while(ttc--)
#define I_L while(true)


//*_______________________________________________________________________________________________

class Node{
    public:
      int data;
      Node *next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

//!_______________________________________________________________________________________________

/* 1 */ void Insert_at_head(Node * &head, int val);
/* 2 */ void Insert_at_anyPosition(Node *head, int pos, int val);
/* 3 */ void Insert_at_tail(Node * &head, Node *&tail, int val);
/* 4 */ void Delete_Head(Node * &head);
/* 5 */ void Delete_any_position(Node *head, int pos);
/* 6 */ void Delete_tail(Node *&head);
/* 7 */ void Take_a_Linked_List_as_Input(Node *&head, Node *&tail);
/* 8 */ void Size_of_a_Linked_List(Node *head);
/* 9 */ void Sort_A(Node *head);
/* 10 */ void Sort_D(Node *head);
/* 11 */ void reverse_R(Node *&head, Node *tmp);  // Using Recursion
/* 11 */ void reverse_L(Node *&head);  // Using Loop
/* 12 */ void Demo_linked_list(Node * &head, Node *&tail, int size);
/* 13 */ void Detect_Cycle_in_Singly_Linked_List(Node *head);
/* 0 */ void Print(Node *head);

//!_______________________________________________________________________________________________

int Size = 0; // O(1)

//!_______________________________________________________________________________________________


int main(){

    Node *head = NULL;
    Node *tail = NULL;

    I_L{
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at any Position" << endl;
        cout << "3. Insert at tail" << endl;
        cout << "4. Delete Head" << endl;
        cout << "5. Delete given position node" << endl;
        cout << "6. Delete tail" << endl;
        cout << "7. Take a Linked List as Input" << endl;
        cout << "8. Size of a Linked List" << endl;
        cout << "9. Sort in Ascending Order" << endl;
        cout << "10. Sort in Descending Order" << endl;
        cout << "11. Reverse" << endl;
        cout << "12. Demo Linked List" << endl;
        cout << "13. Detect Cycle in Singly Linked List" << endl;
        cout << "0. Print Linked List\n\n--> ";

        int choose; cin >> choose;

        switch (choose){

            int val, pos;

            case 1:
                system("cls");
                cout << "Enter Value --> "; 
                cin >> val;
                Insert_at_head(head, val);
                Print(head);
            break;
            
            case 2:
                system("cls");
                Print(head);
                cout << "Enter value -> "; 
                cin >> val;
                cout << "Enter Position [index start with 0]-> "; cin >> pos;
                system("cls");

                if(pos == 0){
                    Insert_at_head(head, val);
                }else{
                    Insert_at_anyPosition(head, pos, val);
                }
                //system("cls");
                Print(head);
            break;
            
            case 3:
                system("cls");
                cout << "Enter Value --> "; 
                cin >> val;
                Insert_at_tail(head, tail, val);
                Print(head);
            break;

            case 4:
                system("cls");
                Delete_Head(head);
                Print(head);
            break;

            case 5:
                system("cls");
                Print(head);
                cout << "Enter Position [index start with 0]-> "; cin >> pos;
                system("cls");
                if(pos == 0){
                    Delete_Head(head);
                }else{
                    Delete_any_position(head, pos);
                }
                Print(head);
            break;

            case 6:
                system("cls");
                Delete_tail(head);
                Print(head);
            break;

            case 7:
                system("cls");
                Take_a_Linked_List_as_Input(head, tail);
                Print(head);
            break;

            case 8:
                system("cls");
                // Size_of_a_Linked_List(head); // O(N)
                cout << Size << endl; // O(1)
                Print(head);
            break;

            case 9:
                system("cls");
                Sort_A(head);
                Print(head);
            break;

            case 10:
                system("cls");
                Sort_D(head);
                Print(head);
            break;

            case 11:
                system("cls");
                cout << "1. Using Recursion" << endl;
                cout << "2. Using Loop" << endl;
                cout << "--> ";
                int new_choose; cin >> new_choose;

                if(new_choose == 1){ reverse_R(head, head); }
                else if(new_choose == 2){ reverse_L(head); }
                else{
                    cout << "Wrong Choose\n" << endl;
                }
                Print(head);
            break;

            case 12:
                system("cls");
                int sz;
                cout << "Enter Demo Linked list Size -> "; cin >> sz;
                Demo_linked_list(head, tail, sz);
                Print(head);
            break;

            case 13:
                system("cls");
                Detect_Cycle_in_Singly_Linked_List(head);
                break;

            case 0:
                system("cls");
                Print(head);
                break;

            default:
                cout << "Wrong Choose\n3" << endl;
                break;
        }
    }
    return 0;
}


//?_______________________________________________________________________________________________

/* 1 */void Insert_at_head(Node * &head, int val){
    //* Time_Complexity --> O(1)

    Size++;
    Node *newNode = new Node(val);

    newNode->next = head;
    head = newNode;
}

//_______________________________________________________________________________________________

/* 2 */void Insert_at_anyPosition(Node *head, int pos, int val){
    //! Method 1:
    //* Time_Complexity --> O(N)
    Size++;
    Node *newNode = new Node(val);
    Node *temp = head;

    // pos--;
    // while(pos--){
    //     temp = temp->next;
    // }
    // newNode->next = temp->next;
    // temp->next = newNode;


    //! Method 2:
    //* Time_Complexity --> O(N)

    if(pos == 0){
        newNode->next = head;
        head = newNode;
    }else{

        for(int i=1; i<=pos-1; i++){
            temp = temp->next;
            if(temp == NULL){
                cout << "Invalid Index" << endl;
                return;
            }
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

//_______________________________________________________________________________________________

/* 3 */void Insert_at_tail(Node *&head, Node *&tail, int val){
    Size++;
    //! Method 1:
    //* Time_Complexity --> O(N)

    Node *new_node = new Node(val);       
    Node *temp = head;

    // if(head == NULL){
    //     head = new_node;
    // }else{
    //     while(temp->next != NULL){
    //         temp = temp->next;
    //     }

    //     temp->next = new_node;
    // }

    //! Method 2:
    //* Time_Complexity --> O(1)

    if(head == NULL){
        head = new_node;
        tail = new_node;
    }else{
        tail->next = new_node;
        tail = new_node;
    }
}

//_______________________________________________________________________________________________

/* 4 */ void Delete_Head(Node * &head){
    Size--;
    //* Time_Complexity --> O(1)

    if(head == NULL){
        cout << "List is Empty" << endl;
        return;
    }

    Node *DeleteNode = head;
    head = head->next;

    delete DeleteNode;
}

//_______________________________________________________________________________________________

/* 5 */ void Delete_any_position(Node *head, int pos){
    Size--;
    //* Time_Complexity --> O(N)

    Node *temp = head;
    Node *DeleteNode;

    for(int i=1; i<=pos-1; i++){
        temp = temp->next;
        if(temp == NULL){
            cout << "Invalid Index" << endl;
            return;
        }
    }
    if(temp->next == NULL){
        cout << "Invalid Index" << endl;
        return;
    }
    DeleteNode = temp->next;
    temp->next = temp->next->next;

    delete DeleteNode;
}

//_______________________________________________________________________________________________

/* 6 */ void Delete_tail(Node *&head){
    Size--;
    //* Time_Complexity --> O(N)

    Node *DeleteNode;
    Node *temp = head;

    if(temp->next == NULL){
        head = NULL;
        return;
    }

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    DeleteNode = temp->next;

    temp->next = NULL;

    delete DeleteNode;
}

//_______________________________________________________________________________________________

/* 7 */ void Take_a_Linked_List_as_Input(Node *&head, Node *&tail){
    while(true){
        Size++;
        int val; cin >> val;
        if(val == -1){ break; }
        
        Node *newNode = new Node(val);

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
}

//_______________________________________________________________________________________________

/* 8 */ void Size_of_a_Linked_List(Node *head){
    //* Time_Complexity --> O(N)
    
    Node *temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    cout << "Size --> " << count << endl;
}

//!____________________________9 & 10 same________________________________________________________

/* 9 */ void Sort_A(Node *head){
    Node *current = head;
    Node *previous;

    while(current != NULL){
        previous = current->next;
        while(previous != NULL){
            if(current->data > previous->data){
                swap(current->data, previous->data);
            }
            previous = previous->next;
        }
        current = current->next;
    }
}

//_______________________________________________________________________________________________

/* 10 */ void Sort_D(Node *head){
    for(Node *i=head; i != NULL; i = i->next){
        for(Node *j=i->next; j != NULL; j = j->next){
            if(i->data < j->data){
                swap(i->data, j->data);
            }
        }
    }
}

//_______________________________________________________________________________________________

/* 11 */ void reverse_R(Node *&head, Node *tmp) {
    if(tmp->next == NULL){
        head = tmp;
        return;
    }
    reverse_R(head, tmp->next);

    tmp->next->next = tmp;
    tmp->next = NULL;
}


/* 11 */ void reverse_L(Node *&head) {
    Node *current = head;
    Node *nxt = NULL;
    Node *previous = NULL;

    while(current != NULL){
        nxt = current->next;
        current->next = previous;
        previous = current;
        current = nxt;
    }

    head = previous;
}

//_______________________________________________________________________________________________

/* 12 */void Demo_linked_list(Node *&head, Node *&tail, int size){
    //* Time_Complexity --> O(N)

    Node *temp = head;

    for(int i=1; i<=size; i++){
        Size++;
        Node *newNode = new Node(i);

        if(head == NULL){
            head = newNode;
            tail = newNode;
            temp = head;
        }else{
            temp->next = newNode;
            tail = newNode;
            temp = temp->next;
        }
    }
}

//!________Hare and Tortoise___OR___Fast and Slow________________________________________________

/* 13 */ void Detect_Cycle_in_Singly_Linked_List(Node *head){
    Node *hare = head;
    Node *tortoise = head;

    bool bl = false;

    while(hare != NULL && hare->next != NULL){
        hare = hare->next->next;
        tortoise = tortoise->next;

        if(hare == tortoise){
            bl = true;
            break;
        }
    }

    if(bl){ cout << "Cycle Detected\n" << endl; }
    else{ cout << "Cycle Not Detected\n" << endl; }
}

//_______________________________________________________________________________________________

void Print(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout << "[ " << temp->data << " ]-->";
        temp = temp->next;
    }
    cout << "[NULL]" << endl;
    cout << endl;
}

//_______________________________________________________________________________________________