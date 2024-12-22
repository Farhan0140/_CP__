#include<bits/stdc++.h>
#include<list>
using namespace std;

#define kill return

#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!Global_Declaration---------------------------------------------------------------------------

list<int>li1;     //Normal Initialization
list<double>li2;  //Normal Initialization
list<char>li3;    //Normal Initialization
list<string>li4;  //Normal Initialization

list<int>li(5);  // with size

list<int>li5(10, 15);   // with size, and filled with 15

// list from another list
list<int>li6 = {1, 2, 3, 4, 5, 4, 6};
list<int>li7(li6);

//!---------------------------------------------------------------------------------------------
void Print(list<int>lli);
void Print0(list<int>lli);
//!---------------------------------------------------------------------------------------------


int main(){
    fast_read();

    //___Size_&_value_pushing___________________________________________________

    cout << "The Max Size of List : " << li1.max_size() << endl;
    cout << "Initial Size : " << li1.size() << endl;
    li1.push_back(2);
    li1.push_back(1);
    li1.push_back(2);
    li1.push_back(4);
    li1.push_back(6);
    cout << "Size after Pushing 5 element : " << li1.size() << endl;

    cout << "Before Push Front : "; Print0(li1);
    // Pushing value from the front
    li1.push_front(1);
    li1.push_front(1);
    li1.push_front(1);
    li1.push_front(9);
    li1.push_front(10);
    li1.push_front(99);
    cout << "After pushing value from the front : "; Print(li1);
    cout << endl;

    //.......Element access.......................
    cout << "Print Front value : " << li1.front() << endl;
    cout << "Print Last value : " << li1.back() << endl;
    /* Using Iterator */ cout << "Using Iterator : "; Print(li1);
    /* Using Auto Iterator */ cout << "Using Auto Iterator : "; Print0(li1);

    //!___Pop Back & Front_______________________________________________________________________

    cout << endl;
    cout << "Before Delete last value : ";
    Print(li1);
    cout << "After Delete last value : ";

    li1.pop_back(); // Delete the last value

    Print(li1);

    cout << "Before Delete The first value : ";
    Print(li1);
    cout << "After Delete the first value : ";

    li1.pop_front(); // Delete the Front value
    
    Print(li1);

    //!____Reverse______________________________________________________________________________

    cout << endl;
    cout << "Before Reverse : "; Print0(li1);
    reverse(li1.begin(), li1.end());
    cout << "After Reverse : "; Print0(li1);

    //!____Sort_________________________________________________________________________________

    cout << endl;
    li1.push_back(2);
    li1.push_back(3);
    li1.push_back(9);
    li1.push_back(5);
    
    cout << "Before Sort : "; Print0(li1);

    li1.sort();

    cout << "After Sort : "; Print0(li1);

    //!____Remove_______________________________________________________________________________

    cout << endl;
    cout << "Before Remove : "; Print(li1);

    li1.remove(1);

    cout << "After Removing 1 : "; Print0(li1);

    //!__Unique_________________________________________________________________________________

    cout << endl;
    cout << "Before Unique : "; Print0(li1);

    li1.unique();   //     Pasapashi value gula remove kore dei

    cout << "After Unique : "; Print0(li1);

    //!___Swap__________________________________________________________________________________

    cout << endl;
    cout << "Before Swap li1 : "; Print0(li1);
    cout << "Before Swap li6 : "; Print0(li6);

    li1.swap(li6);

    cout << "After Swap li1 : "; Print0(li1);
    cout << "After Swap li6 : "; Print0(li6);

    //!___Merge_________________________________________________________________________________

    cout << endl;
    cout << "Before Merge li1 : "; Print0(li1);
    cout << "Before Merge li6 : "; Print0(li6);

    li1.merge(li6);

    cout << "After Merge li1 : "; Print0(li1);
    cout << "After Merge li6 : "; Print0(li6);

    //!___Insert________________________________________________________________________________

    cout << "Before Insert value : "; Print(li1);
    list<int>::iterator itt;   // first We need Iterator to point the Index
    itt = li1.begin();   // assign the first index

    advance(itt, 3);   // Now Itt point the 3 index

    li1.insert(itt, 999);  // Insert 999 in index 3

    cout << "After Insert value in index 3 : "; Print(li1);

    li1.insert(itt, 5, 404); // inserting 404, 5 times in index 3

    cout << "After Inserting 404, 5 times in index 3 : "; Print(li1);

    //!___Erase_________________________________________________________________________________

    cout << endl;
    cout << "Before erase li1 : "; Print(li1);

    list<int>::iterator it1, it2;   // first We need Iterator to point the value

    it1 = li1.begin();    // Store the first value in Iterator 
    li1.erase(it1);     // then Erase the Iterator

    cout << "After erase first value : "; Print(li1);

    // For erase index

    it1 = li1.begin();
    advance(it1, 3);

    li1.erase(it1);

    cout << "After erase Index 3 : "; Print(li1);

    // For Range

    it1 = li1.begin();
    it2 = li1.begin();
    advance(it2, 6);

    li1.erase(it1, it2);

    cout << "After erase Index 1st to 6th : "; Print(li1);


    //!___Clear & Empty_________________________________________________________________________

    cout << endl;
    cout << "Before clearing : ";
    if(li1.empty()){
        cout << "List li1 is empty" << endl;
    }else{
        cout << "List li1 is Not_empty" << endl;
    }

    li1.clear();

    cout << "After clearing : ";
    if(li1.empty()){
        cout << "List li1 is empty" << endl;
    }else{
        cout << "List li1 is Not_empty" << endl;
    }

    kill 0;
}


//!---------------------------------------------------------------------------------------------
void Print(list<int>lli){
    list<int>:: iterator it;
    for(it = lli.begin(); it != lli.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void Print0(list<int>lli){
    for(auto it: lli){
        cout << it << " ";
    }
    cout << endl;
}
//!---------------------------------------------------------------------------------------------