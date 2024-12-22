#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

// BINOMIAL_COEFFICIENT_USING_MODULO {
        ll Factorial(ll n);
        void nCr();
// }


ll B_E(ll base, ll power);

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){

        nCr();
        
    }
}

//?----------------------------------------------------------------------------------------------


//*__________________________BINOMIAL_COEFFICIENT_USING_MODULO___________________________________

ll Factorial(ll n){
    ll result = 1;
    for(ll i=2; i<=n; i++){
        result = (result * i) % Mod;
    }
    return result % Mod;
}

void nCr(){
    ll n, r; cin >> n >> r;
    ll n1 = Factorial(n); 
    ll r1 = Factorial(r);
    ll k = Factorial(n-r);

    ll ans=n1, ans1, ans2;
    ans1 = B_E(r1, Mod-2);    // BINARY_EXPONENTIATION
    ans2 = B_E(k, Mod-2);    // BINARY_EXPONENTIATION

    ans = (ans*ans1) % Mod;
    ans = (ans*ans2) % Mod;

    ans = ans % Mod;

    cout << ans << endl;
}


//*_______________________________________________________________________________________________

//*___________________BINARY_EXPONENTIATION_____________________________

ll B_E(ll base, ll power){
    ll result = 1;
    while(power){
        if(power%2 != 0){
            result = (result*base) % Mod;
            power--;
        }else{
            base = (base*base) % Mod;
            power /= 2;
        }
    }
    return result % Mod;
}