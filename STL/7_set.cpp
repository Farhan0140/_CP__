#include<bits/stdc++.h> // Set always removes the same value. and sorted to ascending ordering 
using namespace std;


//!Global_Declaration------------------------------------------------------


set<int>st1;     //Normal Initialization
set<int>st2;  //Normal Initialization
set<char>st3;    //Normal Initialization
set<string>st4;  //Normal Initialization

//_______________________________________________________________________________________________

void Print(set<int>stt);   // Using iterator & begin(), end()
void Print0(set<int>stt);  // Using auto iterator

//_______________________________________________________________________________________________


int main(){

    //___Size__Capacity____________________________________________________
    cout << "The Max Size of Set : " << st1.max_size() << endl;
    st1.insert(1);
    st1.insert(2);
    st1.insert(3);
    st1.insert(4);
    st1.insert(1);
    st1.insert(1);
    st1.insert(5);
    st1.insert(5);
    cout << "Size after Inserting 8 element Size: " << st1.size() << " : "; Print0(st1);

    //!--' = '--------------------------------------------------------------
    cout << endl;
    cout << "Size Before st2 : " << st2.size() << endl;
    st2 = st1;
    cout << "Size after st2 initializing st1 to st2 : " << st2.size() << endl;

    //!--' Emplace '--------------------------------------------------------------
    cout << endl;
    st2.emplace(6);
    st2.emplace(6);  // Like Insert Function
    st2.emplace(7);
    st2.emplace(8);
    cout << "Size after Emplace st2 : " << st2.size() << " : "; Print0(st2);

    //!--' Swap '--------------------------------------------------------------
    cout << endl;
    cout << "Before Swap st1: " ; Print(st1);
    cout << "Before Swap st2: " ; Print(st2);

    st1.swap(st2);

    cout << "After Swap st1: " ; Print(st1);
    cout << "After Swap st2: " ; Print(st2);

    //!--' Clear & Empty '--------------------------------------------------------------
    cout << endl;
    cout << "Size Before Clear st2 : " << st2.size() << endl;

    st2.clear();
    
    cout << "Size After Clear st2 : " << st2.size() << endl;

    if(st2.empty()){ cout << "St2 is Empty" << endl; }
    else{ cout << "St2 Not Empty" << endl; }

    //!--' Erase '--------------------------------------------------------------
    cout << endl;
    cout << "Before Erase 2 & 3: "; Print0(st1);

    st1.erase(2);
    st1.erase(3);

    cout << "After Erase 2 & 3: "; Print0(st1);

    //-------------
    set<int>:: iterator it1;
    it1 = st1.begin();
    st1.erase(it1);
    cout << "After Erase 1st Index: "; Print0(st1);

    advance(it1, 2);
    st1.erase(it1);
    cout << "After Erase 3rd Index: "; Print0(st1);

    //!--' Find '--------------------------------------------------------------
    cout << endl;
    set<int>:: iterator it2;
    it2 = st1.find(5);      // auto it2 = st1.found(5);  same....

    if(it2 != st1.end()){ cout << "5 Found" << endl; }
    else{ cout << "5 Not Found" << endl; }

    //!--' Upper_Bound '--------------------------------------------------------------
    cout << endl;
    set<int>:: iterator it3;
    it3 = st1.upper_bound(4);

    if(it3 == st1.end()){
        cout << "The element is larger or equal to the Greater element" << endl;
    } else {
        cout << "The upper Bound of 4 is " << *it3 << endl;
    }

    it3 = st1.upper_bound(9);

    if(it3 == st1.end()){
        cout << "The element is larger or equal to the Greater element" << endl;
    } else {
        cout << "The upper Bound of 9 is " << *it3 << endl;
    }

    it3 = st1.upper_bound(100);

    if(it3 == st1.end()){
        cout << "The element is larger or equal to the Greater element" << endl;
    } else {
        cout << "The upper Bound of 4 is " << *it3 << endl;
    }

    //!--' Lower_Bound '--------------------------------------------------------------
    cout << endl;

    set<int>:: iterator it4;
    it4 = st1.lower_bound(4);

    if(it4 == st1.end()){
        cout << "The element is larger to the Greater element" << endl;
    } else {
        cout << "The Lower Bound of 4 is " << *it4 << endl;
    }

    it4 = st1.lower_bound(8);

    if(it4 == st1.end()){
        cout << "The element is larger to the Greater element" << endl;
    } else {
        cout << "The Lower Bound of 8 is " << *it4 << endl;
    }

    it4 = st1.lower_bound(100);

    if(it4 == st1.end()){
        cout << "The element is larger to the Greater element" << endl;
    } else {
        cout << "The Lower Bound of 100 is " << *it4 << endl;
    }

    //!--' Count '--------------------------------------------------------------
    cout << endl;

    int cnt = st1.count(4);   // It returns 0 and 1 because of set content only unique value
    cout << "4 appear in this set " << cnt << " times" << endl;

    return 0;
}


//_______________________________________________________________________________________________

void Print(set<int>stt){
    set<int>:: iterator it;

    for(it= stt.begin(); it!=stt.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


void Print0(set<int>st){
    for(auto it: st){
        cout << it << " ";
    }
    cout << endl;
}

//_______________________________________________________________________________________________