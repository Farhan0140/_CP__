#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

/* EUCLID_ALGORITHM --> GCD */ ll GCD(ll a, ll b);

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){
        ll x, y; cin >> x >> y;
        cout << GCD(x, y) << endl;
    }
}

//?----------------------------------------------------------------------------------------------


//*_______________________________EUCLID_ALGORITHM --> GCD________________________________________

ll GCD(ll a, ll b){
    if(b == 0){
        return a;
    }
    return GCD(b, (a%b));
}

//*_______________________________________________________________________________________________