#include<bits/stdc++.h>
#include<vector>
using namespace std;

#define ll long long int
#define I_HATE_PROGRAMMING int main

#define kill return

#define tc ll tcc; cin >> tcc; while(tcc--)
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!Global_Declaration------------------------------------------------------


vector<int>v1;     //Normal Initialization
vector<double>v2;  //Normal Initialization
vector<char>v3;    //Normal Initialization
vector<string>v4;  //Normal Initialization

vector<int>v(10);  // with size

vector<int>v5(10, 15);   // with size, and filled with 15

// Vector from another Vector
vector<int>v6 = {1, 2, 3, 4, 5, 4, 6};
vector<int>v7(v6);


// 2D------------

vector<vector<int>> v8(100, vector<int>(100)); // v8[100][100]
vector<vector<int>> _2d; // _2d[....][....]


//!------------------------------------------------------------------------
void Print(vector<int>vv);
void Print0(vector<int>vv);
void Print1(vector<int>vv);
void Print2(vector<int>vv);
//!------------------------------------------------------------------------

I_HATE_PROGRAMMING(){
    fast_read();

    //___Size__Capacity____________________________________________________
    cout << "The Max Size of Vector : " << v1.max_size() << endl;
    cout << "Initial Size : " << v1.size() << endl;
    cout << "Initial Capacity : " << v1.capacity() << endl;
    v1.push_back(110);
    v1.push_back(2);
    v1.push_back(333);
    v1.push_back(4);
    v1.push_back(590);
    v1.push_back(6);
    cout << "Size after Pushing 5 element : " << v.size() << endl;
    cout << "Capacity after Pushing 5 element : " << v.capacity() << endl;
    //Size is the number of elements in the vector
    //capacity is the allocated memory to the vector
    //When the capacity is full for the next element to be added
    // the capacity of the vector or the allocated memory for the vector will be doubled

    //.......Element access.......................

    cout << "Print Front value : " << v1.front() << endl;
    cout << "Print Last value : " << v1.back() << endl;

    /* 1 */  //cout << "Reference Operator v1[2] : " << v1[2] << endl;
    /* 2 */  //cout << "at(2) : " << v1.at(2) << endl;

    // Difference Between 1 & 2

    // cout << v1[50] << endl;      // Print Garbage Value
    // cout << v1.at(50) << endl;   // print '--> Warning Massage'
    
    //!--Pop_Back--------------------------------------------------------------

    cout << endl;
    cout << "Before Delete last value : ";
    Print(v1);
    cout << "After Delete last value : ";
    v1.pop_back(); // Delete the last value
    Print(v1);

    //!--Reverse----------------------------------------------------------------------

    cout << endl;
    cout << "Before Reverse : "; Print0(v1);
    reverse(v1.begin(), v1.end());
    cout << "After Reverse : "; Print0(v1);

    //!--Sort----------------------------------------------------------------------
    
    cout << endl;
    v1.push_back(6999);
    v1.push_back(55);
    v1.push_back(1);
    v1.push_back(123);
    
    cout << "Before Sort : "; Print0(v1);

    sort(v1.begin(), v1.end());
    //                         Comparator
    sort(v1.begin(), v1.end(), greater<int>()); //
    sort(v1.rbegin(), v1.rend());               // ---> descending

    cout << "After Sort : "; Print0(v1);

    //!---Swap---------------------------------------------------------------------

    cout << endl;
    cout << "Before Swap V1: " ; Print2(v1);
    cout << "Before Swap V6: " ; Print2(v6);

    swap(v1, v6);

    cout << "After Swap V1: " ; Print2(v1);
    cout << "After Swap V6: " ; Print2(v6);

    //!--Clear & Empty----------------------------------------------------------------------

    cout << endl;
    cout << "Before clearing : ";
    if(v1.empty()){
        cout << "Vector v1 is empty" << endl;
    }else{
        cout << "Vector v1 is Not_empty" << endl;
    }

    v1.clear();

    cout << "After clearing : ";
    if(v1.empty()){
        cout << "Vector v1 is empty" << endl;
    }else{
        cout << "Vector v1 is Not_empty" << endl;
    }

    //!------------------------------------------------------------------------

    //___Inserting_________________________________________________

    cout << endl;
    cout << "Before Insert V6:" ; Print2(v6);

    // v6.insert(v6.begin(), 9999);
    // v6.insert(v6.begin()+2, 9999);       // Types of Inserting
    // v6.insert(v6.begin(), 5, 9999);
    // v6.insert(v6.begin()+2, 5, 9999);
    v6.insert(v6.begin()+5,v7.begin(),v7.end());  //For inserting another vector
    
    cout << "After Insert V6:" ; Print2(v6);
    //!------------------------------------------------------------------------

    //___Erasing_________________________________________________

    cout << endl;
    cout << "Before Erase V6:" ; Print2(v6);

    v6.erase(v6.begin());     //for single erase
    // v6.erase(v6.begin()+1);
    // v.erase(v.begin()+2,v.begin()+5);     //For multiple erase
    // v6.erase(v6.begin()+2, v6.end());
    
    cout << "After Erase V6:" ; Print2(v6);
    //!------------------------------------------------------------------------

    //___Resizing_V6___________________________________________________________
    
    cout << endl;
    cout << "Before Resizing V6:" ; Print2(v6);

    v6.resize(4);

    cout << "After Resizing V6: " ; Print2(v6);
    //!------------------------------------------------------------------------

    
    //___Vector replace and Finding____________________________________________

    cout << endl;
    vector<int>v1={1,2,33,4,5,33,5,33,7,8,33};
    cout << "Before Replace V1:" ; Print2(v1);

    replace(v1.begin(),v1.end(),33,1010);     //replacing 33 with 1010

    cout << "After Replace V1:" ; Print2(v1);


    // Finding uses Iterator
    // cout<<find(v.begin(),v.end(),3);   //gives error coz find returns iterators

    // vector<int>::iterator itt;
    // itt = find(v1.begin(),v1.end(), 3);
    // cout << *itt;//cant print iterator Thats why we'll have to print reference

    auto itt = find(v1.begin(), v1.end(), 3);

    if(itt == v1.end()){ 
        cout << "Not found" << endl;
    }else{ 
        cout << "Found" << endl;
    }
    //!------------------------------------------------------------------------

    //___Maximum / Minimum_____________________________________________________

    cout << endl;

    int Max = *max_element(v1.begin(), v1.end());
    int Min = *min_element(v1.begin(), v1.end());

    cout << "Maximum number in v1: " << Max << endl;
    cout << "Minimum number in v1: " << Min << endl;

    // Position of Max Element 
    auto MAX = max_element(v1.begin(), v1.end());  // return iterator
    int Max_Element_Position = MAX - v1.begin();


    //___User_input____________________________________________________________

    cin.ignore();
    for(int i=0; i<10; i++){
        string s;
        getline(cin, s);
        v4.push_back(s);
    }

    for(string str:v4){
        cout << str << " ";
    }
    cout << endl;

    //___Vector_Pair____________________________________________________________

    cout << endl;
    vector<pair<int, int>> v_p = {{1, 2}, {2, 3}, {3, 4}};

    vector<pair<int, int>>::iterator itp;

    for (itp = v_p.begin(); itp != v_p.end(); itp++){
        cout << (*itp).first << " " << (*itp).second << endl;
    }

    //___Vector_Assign__________________________________________________________
    
    cout << endl;
    cout << "V1 before assign : " ; Print0(v1);

    set<int>st = {1,1,1,1,11,1,1,1,2,3};
    v1.assign(st.begin(), st.end());

    cout << "V1 After assign : " ; Print0(v1);

    // or
    v1.assign(5, -2);  //-----> -2 -2 -2 -2 -2


    //___Iterator______________________________________________________________
    // begin
    // end
    // rbegin --> reverse begin
    // rend --> reverse end

    // Ex Print0
    vector<int>V= {1, 2, 3, 4, 5, 4, 6}; //  1 2 3 4 5 4 6 _
                                  //  begin->1             end-> _  || --end()->6
                                  // ++begin()-> 2
    Print0(V);
    kill 0;
}



//!------------------------------------------------------------------------
void Print(vector<int>vv){
    for(int i=0; i<vv.size(); i++){
        cout << vv[i] << " ";
    }
    cout << endl;
}

void Print0(vector<int>vv){

    //vector<int>::iterator it;    // vector< Data_type > ::iterator Iterator_Name

    // for(it=vv.begin(); it != vv.end(); it++){
    //     cout << *it << " ";
    // }

    for(auto it=vv.rbegin(); it!=vv.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void Print1(vector<int>vv){
    for(auto it: vv){          // Auto Iterator
        cout << it << " ";
    }
    cout << endl;
}

void Print2(vector<int>vv){
    for(int i:vv){
        cout << i << " ";
    }
    cout << endl;
}
//!------------------------------------------------------------------------