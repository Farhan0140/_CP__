#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

const   int    mod = 1e9 + 7;
#define ll     long long int


ll Multiplication(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll power_2(ll n, ll k) {
    ll res = 1;

    while(k > 0) {
        if(k%2 == 1) {
            res = Multiplication(res, n);
            k--;
        } else {
            n = Multiplication(n, n);
            k /= 2;
        }
    }
    return res;
}

//--------------------->

ll power_1(ll n, ll k) {
    ll res = 1LL;
    while(k) {
        if(k & 1) {
            res = (1LL * (res % mod) * (n % mod)) % mod;
        }

        n = 1LL * n * n % mod;
        k >>= 1; // k /= 2; Same
    }

    return res;
}


//--------------------->

ll power_3 (ll n, ll k) {
    if(k == 0) {
        return 1LL;
    }

    ll res = power_3(n, k >> 1);

    if(k & 1) {
        return 1LL * res * res * n % mod;
    }
    return 1LL * res * res % mod;
}

//_______________________________________________________________________________________________


int main(){
    ll n, k; cin >> n >> k;

    cout << power_1(n, k) << endl;
    cout << power_2(n, k) << endl;
    cout << power_3(n, k) << endl;
    return 0;
}


//_______________________________________________________________________________________________