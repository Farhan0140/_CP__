#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

/* BINARY_EXPONENTIATION */ ll Power(ll base, ll power);

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){
        ll x, y; cin >> x >> y;
        cout << x << "^" << y << " = " << Power(x, y) << endl;
    }
}

//?----------------------------------------------------------------------------------------------


//*____________________________________BINARY_EXPONENTIATION____________________________________

ll Power(ll base, ll power){
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

//*_______________________________________________________________________________________________