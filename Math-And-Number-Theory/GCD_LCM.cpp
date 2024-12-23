#include <bits/stdc++.h>
using namespace std;
#define ll long long

// GCD ---> Greatest Common Divisor
// LCM ---> Least Common Multiple

//_______________________________________________________________________________________________

ll GCD(ll n, ll m) {
    return __gcd(n, m);               // TC: O(log(min(n, m)))
}

ll LCM(ll n, ll m) {
    return ((n*m) / __gcd(n, m));     // TC: O(log(min(n, m)))
}

ll LCM_1(ll n, ll m) {
    return ((n / __gcd(n, m)) * m);   // TC: O(log(min(n, m)))
}                                     // For reduce overflow

//_______________________________________________________________________________________________


int main(){
    cout << LCM_1(16, 24);
    return 0;
}


//_______________________________________________________________________________________________