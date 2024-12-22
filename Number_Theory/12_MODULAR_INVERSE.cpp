#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

/* MODULAR_INVERSE */ void M_I(ll a, ll b, ll m);


ll B_E(ll base, ll power);

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){
        int a, b, m;
        cin >> a >> b >> m;
        M_I(a, b, m);
    }
}

//?----------------------------------------------------------------------------------------------


//*____________________________________MODULAR_INVERSE___________________________________________

void M_I(ll a, ll b, ll m){
    ll x = B_E(b, m-2);        //TODO BINARY_EXPONENTIATION er vitore o m pathate hobe & sob jaigai m dara MOD korte hobe
    x %= m;

    ll ans1 = (a * x) % m; 
    ll ans2 = ((a % m) * (x % m)) % m;

    cout << ans1 << endl;
    cout << ans2 << endl;
}


//*_______________________________________________________________________________________________



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