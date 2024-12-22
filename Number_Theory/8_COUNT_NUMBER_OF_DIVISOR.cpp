#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

/* COUNT_NUMBER_OF_DIVISOR */ void C_D(ll n);

set<ll>div_set;

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){
        ll a; cin >> a;

        C_D(a);

        cout << "Divisor of " << a << " : " << div_set.size() << " --> ";

        for(auto it: div_set){
            cout << it << " ";
        }
        cout << endl;

        div_set.clear();
    }
}

//?----------------------------------------------------------------------------------------------


//*_________________PRINT_AND_COUNT_NUMBER_OF_DIVISOR_IN_N________________________________________

void C_D(ll n){
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            ll x = i;
            ll y = n/i;
            div_set.insert(x);
            div_set.insert(y);
        }
    }
}

//*_______________________________________________________________________________________________