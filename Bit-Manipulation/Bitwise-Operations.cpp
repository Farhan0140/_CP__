// check_kth_bit_on_or_off
// print_on_and_off_bits
// turn_on_kth_bit
// turn_off_kth_bit
// toggle_kth_bit

#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

bool check_kth_bit_on_or_off(int n, int k) { //-----> TC: O(1)
    return ((n>>k) & 1);
}


void print_on_and_off_bits(int n) {  //-------> TC: almost O(1)
    for(int k=8; k>=0; k--) {
        if(check_kth_bit_on_or_off(n, k)) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
}


int turn_on_kth_bit(int n, int k) { //-----> TC: O(1)
    return(n | (1 << k));
}


int turn_off_kth_bit(int n, int k) { //-----> TC: O(1)
    return (n & (~(1 << k)));
}


int toggle_kth_bit(int n, int k) { //-----> TC: O(1)
    return (n ^ (1 << k));
}


//_______________________________________________________________________________________________


int main(){
    int n = 45;
    // (check_kth_bit_on_or_off(n, 4))? cout << "on" : cout << "off";
    // print_on_and_off_bits(n);
    // cout << turn_on_kth_bit(n, 4);
    // cout << turn_off_kth_bit(n, 3);
    // cout << toggle_kth_bit(n, 5);
    return 0;
}


//_______________________________________________________________________________________________