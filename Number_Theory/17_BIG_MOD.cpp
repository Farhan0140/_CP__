#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

/* BIG_MOD */ ll Big_Mod(ll base, ll power, ll mod);

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){
        int x, y, m, ans;
        cin >> x >> y >> m;
        ans = Big_Mod(x, y, m);
        cout << ans << endl;
    }
}

//?----------------------------------------------------------------------------------------------


//*__________________________________________BIG_MOD_____________________________________________

ll Big_Mod(ll base, ll power, ll mod){
    if(power == 0){
        return 1;
    }
    if(power%2 != 0){
        ll a = base%mod;
        ll b = (Big_Mod(base, power-1, mod));
        return (a*b)%mod;
    }
    else if(power%2 == 0){
        ll a = (Big_Mod(base, power/2, mod));
        return (a*a)%mod;
    }
    return -404;
}

//*_______________________________________________________________________________________________