#include <bits/stdc++.h>
using namespace std;


//_______________________________________________________________________________________________


int main(){
    int n = 15;

    // Output Binary Representation -->
                                    //         7 6 5 4 3 2 1 0
    cout << bitset<8>(n) << endl;   // ------> 0 0 0 0 1 1 1 1


    // Find max set bit
    cout << __lg(n) << endl;        // ------> 3


    // Count Set Bits
    cout << __builtin_popcount(n) << endl;    //----> 4


    // Binary Representation to string
    bitset<8> tmp(n);
    string s = tmp.to_string();
    cout << s << endl;          //----> 00001111

    return 0;
}



//_______________________________________________________________________________________________