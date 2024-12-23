#include <bits/stdc++.h>
using namespace std;

const   int    mod = 1e9 + 7;
#define ll     long long int


//_______________________________________________________________________________________________

// Addition

ll Addition(ll a, ll b) {
    return ((a % mod) + (b % mod)) % mod;
}

// Subtraction

ll Subtraction(ll a, ll b) {
    return ((a % mod) - (b % mod)) % mod;
}

// Multiplication

ll Multiplication(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll Multiplication(ll a, ll b, ll c) {
    return (((a % mod) * (b % mod)) % mod * (c % mod)) % mod;
}


//_______________________________________________________________________________________________


int main(){
    return 0;
}


//_______________________________________________________________________________________________