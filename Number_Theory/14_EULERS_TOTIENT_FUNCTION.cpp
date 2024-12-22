#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

/* EULER'S_TOTIENT_FUNCTION */ void E_T_F(ll n);

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){
        int n;
        cin >> n;
        E_T_F(n);
    }
}

//?----------------------------------------------------------------------------------------------


//*________________________________EULER'S_TOTIENT_FUNCTION______________________________________

void E_T_F(ll n){      // using PRIME_FACTORIZATION
    ll ans = n;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            while(n%i == 0){
                n /= i;
            }
            ans *= (i-1);
            ans /= i;
        }
    }
    if(n > 1){
        ans *= (n-1);
        ans /= n;
    }
    cout << ans << endl;
}


//*_______________________________________________________________________________________________