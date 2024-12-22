// Like Vector except pop_front(), push_front()

#include<bits/stdc++.h>
#include<deque>
using namespace std;

#define kill return

#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!Global_Declaration---------------------------------------------------------------------------

deque<int>dq;     //Normal Initialization
deque<double>dq1;  //Normal Initialization
deque<char>dq2;    //Normal Initialization
deque<string>dq3;  //Normal Initialization

deque<int>dq4(5);  // with size

deque<int>dq5(10, 15);   // with size, and filled with 15

// deque from another deque
deque<int>dq6 = {1, 2, 3, 4, 5, 4, 6};
deque<int>dq7(dq6);

//!---------------------------------------------------------------------------------------------
void Print(deque<int>dqq);   // Using Iterator
void Print0(deque<int>dqq);  // Using Auto Iterator
void Print1(deque<int>dqq);  // Using at
void Print2(deque<int>dqq);  // Like Array
//!---------------------------------------------------------------------------------------------


int main(){
    fast_read();

    //___Size__&_value_push__________________________________________________

    cout << "The Max Size of deque : " << dq.max_size() << endl;
    cout << "Initial Size : " << dq.size() << endl;
    dq.push_back(2);
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(4);
    dq.push_back(6);
    cout << "Size after Pushing 5 element : " << dq.size() << endl;

    cout << "Before Push Front : "; Print0(dq);
    // Pushing value from the front
    dq.push_front(1);
    dq.push_front(1);
    dq.push_front(1);
    dq.push_front(9);
    dq.push_front(10);
    dq.push_front(99);
    cout << "After pushing value from the front : "; Print(dq);
    cout << endl;

    //.......Element access.......................
    
    cout << "Print Front value : " << dq.front() << endl;
    cout << "Print Last value : " << dq.back() << endl;
    cout << "Print Using at() : " << dq.at(5) << endl;
    cout << "Print Using A[] : " << dq[4] << endl;

    cout << endl;
    /* Using Iterator */ cout << "Using Iterator : "; Print(dq);
    /* Using Auto Iterator */ cout << "Using Auto Iterator : "; Print0(dq);
    /* Using At */ cout << "Using at() function : "; Print1(dq);
    /* Like Array */ cout << "Like Array A[] : "; Print2(dq);

    //!__Pop Back & Front_______________________________________________________________________

    cout << endl;
    cout << "Before Delete last value : ";
    Print(dq);
    cout << "After Delete last value : ";
    dq.pop_back(); // Delete the last value
    Print(dq);

    cout << "Before Delete The first value : ";
    Print(dq);
    cout << "After Delete the first value : ";
    dq.pop_front(); // Delete the Front value
    Print(dq);

    //!___Insert________________________________________________________________________________

    cout << endl;
    cout << "Before Insert value : "; Print(dq);
    deque<int>::iterator itt;   // first We need Iterator to point the Index
    itt = dq.begin();   // assign the first index

    dq.insert(itt, 999);  // Insert 999 in first

    cout << "After Insert value in begin : "; Print(dq);

    itt = dq.begin()+2;
    dq.insert(itt, 808); // inserting 808, in index 3

    itt = dq.begin()+2;
    dq.insert(itt, 5, 111); // inserting 111, 5 times in index 3

    cout << "After Inserting 111, 5 times in index 3 : "; Print(dq);

    //!___Erase_________________________________________________________________________________

    cout << endl;
    cout << "Before erase dq : "; Print(dq);

    deque<int>::iterator it1, it2;   // first We need Iterator to point the value

    it1 = dq.begin();    // Store the first value in Iterator 
    dq.erase(it1);     // then Erase the Iterator

    cout << "After erase first value : "; Print(dq);

    // For Range

    it1 = dq.begin();
    it2 = dq.begin()+5;

    dq.erase(it1, it2);

    cout << "After erase Index 1st to 5th : "; Print(dq);


    //!___Clear & Empty_________________________________________________________________________

    cout << endl;
    cout << "Before clearing : ";
    if(dq.empty()){
        cout << "Deque dq is empty" << endl;
    }else{
        cout << "Deque dq is Not_empty" << endl;
    }

    dq.clear();

    cout << "After clearing : ";
    if(dq.empty()){
        cout << "Deque dq is empty" << endl;
    }else{
        cout << "Deque dq is Not_empty" << endl;
    }

    kill 0;
}


//!---------------------------------------------------------------------------------------------
void Print(deque<int>dqq){
    deque<int>:: iterator it;
    for(it = dqq.begin(); it != dqq.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void Print0(deque<int>dqq){
    for(auto it: dqq){
        cout << it << " ";
    }
    cout << endl;
}

void Print1(deque<int>dqq){
    for(int i=0; i<dqq.size(); i++){
        cout << dqq.at(i) << " ";
    }
    cout << endl;
}

void Print2(deque<int>dqq){
    for(int i=0; i<dqq.size(); i++){
        cout << dqq[i] << " ";
    }
    cout << endl;
}
//!---------------------------------------------------------------------------------------------