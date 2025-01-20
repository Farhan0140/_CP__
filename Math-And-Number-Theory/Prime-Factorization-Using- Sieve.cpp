#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int S = 1e5;


// TC O(nloglogn  +   K    +   logn)
//      Seive         primes   map
//_______________________________________________________________________________________________

vector<ll> primes;

void sieve() {
    vector<ll> tmp(S, true);

    for(int i=2; i*i<=S; i++) {
        if(tmp[i]) {
            for(int j=i+i; j<=S; j+=i) {
                tmp[j] = false;
            }
        }
    }

    for(ll i = 2; i <= S; i++) {
        if(tmp[i]) {
            primes.push_back(i);
        }
    }
}

//_______________________________________________________________________________________________


int main(){
    sieve();

    ll n; cin >> n;
    map<ll, int> mp;

    for(int i=0; i<primes.size(); i++) {
        if(n <= 1) { break; }
        while(n % primes[i] == 0) {
            mp[primes[i]]++;
            n /= primes[i];
        }
    }

    for(auto [x, k]: mp) {
        cout << x << "^" << k << " ";
    }
    return 0;
}


//_______________________________________________________________________________________________