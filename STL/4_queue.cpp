#include<bits/stdc++.h>
#include<queue>
using namespace std;

#define kill return

#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!Global_Declaration---------------------------------------------------------------------------

// Queue = FIFO -> First in First Out

queue<int>q;     //Normal Initialization
queue<int>q1;
queue<double>q2;  //Normal Initialization
queue<char>q3;    //Normal Initialization
queue<string>q4;  //Normal Initialization

//!---------------------------------------------------------------------------------------------
void Print1(queue<int>qq);
void Print2(queue<int>qq);
//!---------------------------------------------------------------------------------------------


int main(){
    fast_read();

    //___Size__&_value_push__________________________________________________

    cout << "Initial Size : " << q.size() << endl;
    q.push(3);
    q.push(1);
    q.push(7);
    //  as like push function
    q.emplace(4);
    q.emplace(90);
    q.emplace(90);
    cout << "Size after Pushing 5 element : " << q.size() << endl;

    //.......Element access.......................
    
    cout << endl;
    cout << "Print Front value : " << q.front() << endl;
    cout << "Print Last value : " << q.back() << endl;
    
    //!__Pop____________________________________________________________________________________

    cout << endl;
    cout << "Before Delete last value : "; Print1(q);

    q.pop();

    cout << "After Delete last value : "; Print2(q);

    //!___Swap__________________________________________________________________________________

    cout << endl;
    q1.push(1);
    q1.push(1);
    q1.push(1);
    //  as like as push function
    q1.emplace(1);
    q1.emplace(1);
    q1.emplace(1);
    cout << "Before Swap q : "; Print1(q);
    cout << "Before Swap q1 : "; Print2(q1);

    q.swap(q1);

    cout << "After Swap q : "; Print1(q);
    cout << "After Swap q1 : "; Print2(q1);

    kill 0;
}


//!---------------------------------------------------------------------------------------------
void Print1(queue<int>qq){
    while(!qq.empty()){
        cout << qq.front() << " ";   // Printing first value
        qq.pop();   // Removing first value
    }
    cout << endl;
}

void Print2(queue<int>qq){
    while(qq.size() > 0){
        cout << qq.front() << " ";   // Printing first value
        qq.pop();   //   Removing first value
    }
    cout << endl;
}
//!---------------------------------------------------------------------------------------------