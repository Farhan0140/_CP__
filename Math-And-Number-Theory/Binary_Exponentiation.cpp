#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

const   int    mod = 1e9 + 7;
#define ll     long long int


ll Multiplication(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}



ll Power(ll n, ll k) {
    ll res = 1;

    while(k > 0) {
        if(k & 1) {
            res = Multiplication(res, n);
            k--;
        } else {
            n = Multiplication(n, n);
            k /= 2;
        }
    }

    return res;
}

//_______________________________________________________________________________________________


int main(){
    ll n, k; cin >> n >> k;
    cout << Power(n, k) << endl;
    return 0;
}


//_______________________________________________________________________________________________