#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int S = 1e5;

// TC O(sqrt(n))
//_______________________________________________________________________________________________

// Using Map    // log(n) for map
void Prime_Fact(ll n) {
    map<ll, int> cnt;

    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) {
            while(n%i == 0) {
                cnt[i]++;
                n /= i;
            }
        }
    }
    if(n > 1) {
        cnt[n]++;
    }

    for(auto [x, k]: cnt) {
        cout << x << "^" << k << " ";
    }
}


//_______________________________________________________________________________________________


int main(){
    ll n; cin >> n;
    
    return 0;
}


//_______________________________________________________________________________________________