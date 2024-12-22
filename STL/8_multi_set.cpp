#include<bits/stdc++.h> // multiset don't removes the same value. and sorted to ascending ordering 
using namespace std;


//!Global_Declaration------------------------------------------------------


multiset<int>st1;     //Normal Initialization
multiset<int>st2;  //Normal Initialization
multiset<char>st3;    //Normal Initialization
multiset<string>st4;  //Normal Initialization

//_______________________________________________________________________________________________

void Print(multiset<int>stt);   // Using iterator & begin(), end()
void Print0(multiset<int>stt);  // Using auto iterator

//_______________________________________________________________________________________________


int main(){

    //___Size__Capacity____________________________________________________
    cout << "The Max Size of multiset : " << st1.max_size() << endl;
    st1.insert(1);
    st1.insert(2);
    st1.insert(3);
    st1.insert(4);
    st1.insert(4);
    st1.insert(4);
    st1.insert(4);
    st1.insert(1);
    st1.insert(1);
    st1.insert(5);
    st1.insert(5);
    cout << "Size after Inserting 11 element Size: " << st1.size() << " : "; Print0(st1);

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
    cout << "Size after Emplace 4 value in st2 : " << st2.size() << " : "; Print0(st2);

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
    cout << "Before Erase 1 & 3: "; Print0(st1);

    st1.erase(1);
    st1.erase(3);

    cout << "After Erase 1 & 3: "; Print0(st1);

    // If we went to erase only one from many of them__________________________

    cout << "Before Erase Single 4 : "; Print0(st1);
    auto Ite = st1.find(4);
    st1.erase(Ite);

    cout << "After Erase Single 4 : "; Print0(st1);

    //-------------
    multiset<int>:: iterator it1;
    it1 = st1.begin();
    st1.erase(it1);
    cout << "After Erase 1st Index: "; Print0(st1);

    it1 = st1.begin();
    advance(it1, 2);
    st1.erase(it1);
    cout << "After Erase 3rd Index: "; Print0(st1);

    //!--' Find '--------------------------------------------------------------
    cout << endl;
    multiset<int>:: iterator it2;
    it2 = st1.find(5);      // auto it2 = st1.found(5);  same....

    if(it2 != st1.end()){ cout << "5 Found" << endl; }
    else{ cout << "5 Not Found" << endl; }

    //!--' Count '--------------------------------------------------------------
    cout << endl;

    int cnt = st1.count(4);   // It returns how many times is the value in the list
    cout << "4 appear in this multiset " << cnt << " times" << endl;

    //!--' Upper_Bound '--------------------------------------------------------------
    cout << endl;
    multiset<int>:: iterator it3;
    it3 = st1.upper_bound(4);
    
    

    //!--' Lower_Bound '--------------------------------------------------------------
    cout << endl;

    multiset<int>:: iterator it4;
    it4 = st1.lower_bound(4);

    
    return 0;
}


//_______________________________________________________________________________________________

void Print(multiset<int>stt){
    multiset<int>:: iterator it;

    for(it= stt.begin(); it!=stt.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


void Print0(multiset<int>st){
    for(auto it: st){
        cout << it << " ";
    }
    cout << endl;
}

//_______________________________________________________________________________________________