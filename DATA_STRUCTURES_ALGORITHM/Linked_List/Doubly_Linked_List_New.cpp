//TODO Use Vs code [Better Comments] Extension

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define tc int ttc; cin >> ttc; while(ttc--)
#define I_L while(true)


//*_______________________________________________________________________________________________

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

//!_______________________________________________________________________________________________

/* 1 */ void Insert_at_head(Node * &head, Node *&tail, int val);
/* 2 */ void Insert_at_anyPosition(Node *head, int pos, int val); 
/* 3 */ void Insert_at_tail(Node * &head, Node *&tail, int val); 
/* 4 */ void Delete_Head(Node * &head, Node *&tail);
/* 5 */ void Delete_any_position(Node *head, int pos);
/* 6 */ void Delete_tail(Node *&head, Node *&tail);
/* 7 */ void Take_a_Linked_List_as_Input(Node *&head, Node *&tail);
/* 8 */ int Size_of_a_Linked_List(Node *head); 
/* 9 */ void Sort_A(Node *head);
/* 10 */ void Sort_D(Node *head);
/* 11 */ void Demo_linked_list(Node * &head, Node *&tail, int size); 
/* 12 */ void Reverse(Node *head, Node *tail); // Using Two pointer Technique
/* 0 */ void Print_head_to_tail(Node *head); 
/* 0 */ void Print_tail_to_head(Node *tail); 

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
        cout << "11. Demo Linked List" << endl;
        cout << "12. Reverse Linked List Using Two pointer" << endl;
        cout << "0. Print Linked List\n\n--> ";

        int choose; cin >> choose;

        switch (choose){

            int val, pos;

            case 1:
                system("cls");
                cout << "Enter Value --> "; 
                cin >> val;
                Insert_at_head(head, tail, val);
                Print_head_to_tail(head);
            break;
            
            case 2:
                system("cls");
                Print_head_to_tail(head);
                cout << "Enter value -> "; 
                cin >> val;
                cout << "Enter Position [index start with 0]-> "; cin >> pos;
                system("cls");

                if(pos == 0){
                    Insert_at_head(head, tail, val);
                }else if(pos == Size_of_a_Linked_List(head)){
                    Insert_at_tail(head, tail, val);
                }else if(pos > Size_of_a_Linked_List(head)){
                    cout << "Invalid Index" << endl;
                }else{
                    Insert_at_anyPosition(head, pos, val);
                }
                //system("cls");
                Print_head_to_tail(head);
            break;
            
            case 3:
                system("cls");
                cout << "Enter Value --> "; 
                cin >> val;
                Insert_at_tail(head, tail, val);
                Print_head_to_tail(head);
            break;

            case 4:
                system("cls");
                Delete_Head(head, tail);
                Print_head_to_tail(head);
            break;

            case 5:
                system("cls");
                Print_head_to_tail(head);
                cout << "Enter Position [index start with 0]-> "; cin >> pos;
                system("cls");
                if(pos == 0){
                    Delete_Head(head, tail);
                }else{
                    Delete_any_position(head, pos);
                }
                Print_head_to_tail(head);
            break;

            case 6:
                system("cls");
                Delete_tail(head, tail);
                Print_head_to_tail(head);
            break;

            case 7:
                system("cls");
                Take_a_Linked_List_as_Input(head, tail);
                Print_head_to_tail(head);
            break;

            case 8:
                system("cls");
                Size_of_a_Linked_List(head);
                Print_head_to_tail(head);
            break;

            case 9:
                system("cls");
                Sort_A(head);
                Print_head_to_tail(head);
            break;

            case 10:
                system("cls");
                Sort_D(head);
                Print_head_to_tail(head);
            break;

            case 11:
                system("cls");
                int sz;
                cout << "Enter Demo Linked list Size -> "; cin >> sz;
                Demo_linked_list(head, tail, sz);
                Print_head_to_tail(head);
            break;

            case 12:
                system("cls");
                Reverse(head, tail);
                Print_head_to_tail(head);
            break;

            case 0:
                system("cls");
                cout << "1. Print_head_to_tail" << endl;
                cout << "2. Print_tail_to_head" << endl;
                cout << "--> ";
                int new_choose; cin >> new_choose;

                if(new_choose == 1){ Print_head_to_tail(head); }
                else if(new_choose == 2){ Print_tail_to_head(tail); }
                else{
                    cout << "Wrong Choose\n" << endl;
                }
                break;

            default:
                cout << "Wrong Choose\n" << endl;
                break;
        }
    }
    return 0;
}


//?_______________________________________________________________________________________________

/* 1 */void Insert_at_head(Node *&head, Node *&tail, int val){
    //* Time_Complexity --> O(1)

    Node *newNode = new Node(val);

    if(head == NULL){
        newNode = head;
        newNode = tail;
        return;
    }
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
}

//_______________________________________________________________________________________________

/* 2 */void Insert_at_anyPosition(Node *head, int pos, int val){
    //! Method 1:
    //* Time_Complexity --> O(N)

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
        newNode->previous = temp;
        temp->next->previous = newNode;
        temp->next = newNode;
    }
}

//_______________________________________________________________________________________________

/* 3 */void Insert_at_tail(Node *&head, Node *&tail, int val){
    //* Time_Complexity --> O(1)

    Node *newNode = new Node(val);

    if(head == NULL){
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
}

//_______________________________________________________________________________________________

/* 4 */ void Delete_Head(Node *&head, Node *&tail){
    //* Time_Complexity --> O(1)

    if(head == NULL){
        cout << "List is Empty" << endl;
        return;
    }

    Node *DeleteNode = head;
    head = head->next;

    if(head == NULL){
        tail = NULL;
        return;
    }
    head->previous = NULL;

    delete DeleteNode;
}

//_______________________________________________________________________________________________

/* 5 */ void Delete_any_position(Node *head, int pos){
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

/* 6 */ void Delete_tail(Node *&head, Node *&tail){
    //* Time_Complexity --> O(1)

    Node *DeleteNode = NULL;

    if(tail == NULL){
        cout << "List is empty" << endl;
        return;
    }

    DeleteNode = tail;
    tail = tail->previous;

    if(tail == NULL){
        head = NULL;
        return;
    }

    tail->next = NULL;

    delete DeleteNode;
}

//_______________________________________________________________________________________________

/* 7 */ void Take_a_Linked_List_as_Input(Node *&head, Node *&tail){
    while(true){
        int val; cin >> val;
        if(val == -1){ break; }
        
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
}

//_______________________________________________________________________________________________

/* 8 */ int Size_of_a_Linked_List(Node *head){
    //* Time_Complexity --> O(N)
    
    Node *temp = head;
    int count = 0;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
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

/* 11 */ void Demo_linked_list(Node *&head, Node *&tail, int size){
    //* Time_Complexity --> O(N)

    Node *temp = head;

    for(int i=1; i<=size; i++){
        Node *newNode = new Node(i);

        if(head == NULL){
            head = newNode;
            tail = newNode;
            temp = head;
        }else{
            temp->next = newNode;
            newNode->previous = temp;
            tail = newNode;
            temp = temp->next;
        }
    }
}

//_______________________________________________________________________________________________

/* 12 */ void Reverse(Node *head, Node *tail){
    Node *i = head;
    Node *j = tail;

    while(i != j && i->next != j){
        swap(i->data, j->data);
        i = i->next;
        j = j->previous;
    }

    swap(i->data, j->data);   // Jokhon node sonkha even thakbe,, tokhon i->next != j er jonno loop break hoe jabe tai baire ekbar swap korci,, ete kono problem nai
}

//_______________________________________________________________________________________________

/* 0 */ void Print_head_to_tail(Node *head){
    //* Time_Complexity --> O(N)

    Node *temp = head;

    while(temp != NULL){
        cout << "[ " << temp->data << " ]-->";
        temp = temp->next;
    }
    cout << "[NULL]" << endl;
    cout << endl;
}

//_______________________________________________________________________________________________

/* 0 */ void Print_tail_to_head(Node *tail){
    //* Time_Complexity --> O(N)

    Node *temp = tail;

    while(temp != NULL){
        cout << "[ " << temp->data << " ]-->";
        temp = temp->previous;
    }
    cout << "[NULL]" << endl;
    cout << endl;
}

//_______________________________________________________________________________________________