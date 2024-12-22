#include <bits/stdc++.h>
using namespace std;

#define ll long long

//_______________________________________________________________________________________________

bool Check_Prime_Naive(ll n) {
    if(n == 1) {
        return false;
    }

    for(int i=2; i<n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}


bool Check_Prime_Optimize(ll n) {
    if(n <= 1) { return false; }
    if(n <= 3) { return true; }
    if(n%2 == 0) { return false; }

    for(int i=3; i*i<=n; i += 2) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

//_______________________________________________________________________________________________


int main(){
    ll n; cin >> n;

    // (Check_Prime_Naive(n))? cout << "Prime": cout << "Not Prime";

    (Check_Prime_Optimize(n))? cout << "Prime": cout << "Not Prime";
    return 0;
}


//_______________________________________________________________________________________________