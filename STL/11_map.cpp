#include<bits/stdc++.h>
#include<vector>
using namespace std;

#define ll long long int
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));


//!Global_Declaration------------------------------------------------------
map<string, int> mp1;
map<string, string> mp2;
map<int, int> mp3;



int main() {
    //______Initialization_______________________________________________________________________________
    // Store Unique Key
    //          key      value
    mp1.insert({"Nadim", 100});
    mp1.insert({"Nadim", 10});
    mp1.insert({"Nadim", 90});

    // for(auto it: mp1) {
    //     cout << it.first << " " << it.second << endl;
    // }
    // Output Only Nadim 100;

    mp1.insert({"Farhan", 900});

    mp1["Phitron"] = 69;


    //______Element access_______________________________________________________________________________
    // 1
    // array[]  or  at()
    cout << mp1["Farhan"] << endl;  //--> 900
    cout << mp1.at("Nadim") << endl;  //--> 100

    // 2
    for(auto it: mp1) {
        cout << it.first << " " << it.second << endl;
    }
    //---> Farhan 900
    //---> Nadim 100
    //---> Phitron 69



    //______Find________________________________________________________________________________

    mp1["A"] = 44;
    mp1["B"] = 233;
    mp1["C"] = 99;

    auto it = mp1.find("B"); // Return Iterator

    cout << it->first << " " << it->second << endl;  //---> B 233
    //         Key                value


    auto it1 = mp1.find("Hablu");
    if(it1 == mp1.end()) {
        cout << "Key Not Found\n";
    } else {
        cout << it1->first << " " << it1->second << endl;
    }
    // Output --> Key not found



    cout << endl;
    //______Erase_______________________________________________________________________________
    // remove or delete the Key

    mp1.erase("Phitron");
    for(auto it: mp1) {
        cout << it.first << " " << it.second << endl;
    }
    /*
        A 44
        B 233
        C 99
        Farhan 900
        Nadim 100
    */
    
    cout << endl;

    auto it2 = mp1.find("A");
    if(it2 != mp1.end()) {
        mp1.erase(it2);
    }

    for(auto it: mp1) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}