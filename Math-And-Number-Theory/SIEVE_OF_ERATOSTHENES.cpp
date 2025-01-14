#include <bits/stdc++.h>
using namespace std;

// TC O(n loglog n)

//_______________________________________________________________________________________________

const   int    mod = 1e9 + 7;
#define ll     long long int

void Primes(vector<bool> &v, ll n) {
    for(int i=2; i*i<=n; i++) {
        if(v[i]) {
            for(int j = i+i; j <= n; j += i) {
                v[j] = false;
            }
        }
    }
}

//_______________________________________________________________________________________________


int main() {
    ll n; cin >> n;
    vector<bool> prime_list(n+5, true);

    // Primes(prime_list, n);

    //!__________________________________________________
    auto ok = [&]() {
        for(int i=2; i*i<=n; i++) {
            if(prime_list[i]) {
                for(int j = i+i; j <= n; j += i) {
                    prime_list[j] = false;
                }
            }
        }
    };

    ok();
    //!___________________________________________________

    for(int i=2; i<=n; i++) {
        if(prime_list[i]) {
            cout << i << " ";
        }
    }
    return 0;
}


//_______________________________________________________________________________________________