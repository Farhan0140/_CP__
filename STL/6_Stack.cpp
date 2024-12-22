#include<bits/stdc++.h>
#include<stack>
using namespace std;

#define kill return

#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!Global_Declaration---------------------------------------------------------------------------

// stack = LIFO -> Last in First Out

stack<int>st;    //Normal Initialization
stack<int>st1;
stack<double>st2;  //Normal Initialization
stack<char>st3;    //Normal Initialization
stack<string>st4;  //Normal Initialization

//!---------------------------------------------------------------------------------------------
void Print1(stack<int>stt);
void Print2(stack<int>stt);
//!---------------------------------------------------------------------------------------------


int main(){
    fast_read();

    //___Size__&_value_push__________________________________________________

    cout << "Initial Size : " << st.size() << endl;
    st.push(3);
    st.push(1);
    st.push(7);
    //  as like push function
    st.emplace(4);
    st.emplace(90);
    st.emplace(90);
    cout << "Size after Pushing 5 element : " << st.size() << endl;

    //.......Element access.......................
    
    cout << endl;
    cout << "Printing the value who enters the last : " << st.top() << endl;   // Printing the value who enters the last
    
    //!__Pop____________________________________________________________________________________

    cout << endl;
    cout << "Before Delete last value : "; Print1(st);

    st.pop();

    cout << "After Delete last value : "; Print2(st);

    //!___Swap__________________________________________________________________________________

    cout << endl;
    st1.push(1);
    st1.push(1);
    st1.push(1);
    //  as like as push function
    st1.emplace(1);
    st1.emplace(1);
    st1.emplace(1);
    cout << "Before Swap st : "; Print1(st);
    cout << "Before Swap st1 : "; Print2(st1);

    st.swap(st1);

    cout << "After Swap st : "; Print1(st);
    cout << "After Swap st1 : "; Print2(st1);

    kill 0;
}


//!---------------------------------------------------------------------------------------------
void Print1(stack<int>stt){
    while(!stt.empty()){
        cout << stt.top() << " ";   // Printing the value who enters the last
        stt.pop();   // Removing top value
    }
    cout << endl;
}

void Print2(stack<int>stt){
    while(stt.size() > 0){
        cout << stt.top() << " ";   // Printing the value who enters the last
        stt.pop();   //   Removing top value
    }
    cout << endl;
}
//!---------------------------------------------------------------------------------------------