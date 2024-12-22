#include<bits/stdc++.h>
using namespace std;

#define kill return

#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//*---------Custom Compare Class---------------------------------------------------------------

class Student{
    public:
      string name;
      int roll;
      int marks;

    Student(string name, int roll, int marks) {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class Custom_Compare{  // At first, sorting the class depends on marks. If marks are equal then sort the class depending on roll because rolls are unique.
    public:
      bool operator()(Student a, Student b) {
          if(a.marks < b.marks) {
              return true;
          } else if(a.marks == b.marks) {
              if(a.roll > b.roll) {
                  return true;
              } else {
                  return false;
              }
          } else {
              return false;
          }
      }
};

//*---------------------------------------------------------------------------------------------

//!Global_Declaration---------------------------------------------------------------------------

priority_queue<int>pq;     //Normal Initialization  ---> Max Heap
priority_queue<int>pq1;
priority_queue<double>pq2;  //Normal Initialization
priority_queue<char>pq3;    //Normal Initialization
priority_queue<string>pq4;  //Normal Initialization

// The normal Priority_Queue will always print the larger value
// If we want the Priority_Queue will always print the lower value
// then we need to follow this rule

// priority_queue<int, vector<int>, greater<int>> pq;     // ---> Min Heap

//!---------------------------------------------------------------------------------------------
void Print1(priority_queue<int>pqq);
void Print2(priority_queue<int>pqq);
//!---------------------------------------------------------------------------------------------

// Who will We give More Priority to?
// Of course the biggest value

int main(){
    fast_read();

    //___Size__&_value_push__________________________________________________

    cout << "Initial Size : " << pq.size() << endl;
    pq.push(3);
    pq.push(1);
    pq.push(7);
    //  as like as push function
    pq.emplace(4);
    pq.emplace(90);
    pq.emplace(90);
    cout << "Size after Pushing 6 element : " << pq.size() << endl;

    //.......Element access.......................
    
    cout << endl;
    cout << "Print Front value : " << pq.top() << endl;  //  top() pointing the biggest value in this container 
    
    //!__Pop____________________________________________________________________________________

    cout << endl;
    cout << "Before Delete last value : "; Print1(pq);

    pq.pop();

    cout << "After Delete last value : "; Print2(pq);

    //!___Swap__________________________________________________________________________________

    cout << endl;
    pq1.push(1);
    pq1.push(1);
    pq1.push(1);
    //  as like as push function
    pq1.emplace(1);
    pq1.emplace(1);
    pq1.emplace(1);
    cout << "Before Swap pq : "; Print1(pq);
    cout << "Before Swap pq1 : "; Print2(pq1);

    pq.swap(pq1);

    cout << "After Swap pq : "; Print1(pq);
    cout << "After Swap pq1 : "; Print2(pq1); cout << "\n" << endl;

    cout << "Custom Compare Class:: " << endl;
    
    Student o1("akib", 23, 95);
    Student o2("jobbar", 24, 99);
    Student o3("ali", 25, 100);
    Student o4("kabir", 15, 65);
    Student o5("asif", 55, 65);
    Student o6("tamim", 35, 65);

    priority_queue<Student, vector<Student>, Custom_Compare> PQ;
    PQ.push(o1);
    PQ.push(o2);
    PQ.push(o3);
    PQ.push(o4);
    PQ.push(o5);
    PQ.push(o6);

    while(!PQ.empty()) {
        cout << PQ.top().name << " " << PQ.top().roll << " " << PQ.top().marks << endl;
        PQ.pop();
    }
    kill 0;
}


//!---------------------------------------------------------------------------------------------
void Print1(priority_queue<int>pqq){
    while(!pqq.empty()){
        cout << pqq.top() << " ";   // Printing first value
        pqq.pop();   // Removing first value
    }
    cout << endl;
}

void Print2(priority_queue<int>pqq){
    while(pqq.size() > 0){
        cout << pqq.top() << " ";   // Printing first value
        pqq.pop();   //   Removing first value
    }
    cout << endl;
}
//!---------------------------------------------------------------------------------------------