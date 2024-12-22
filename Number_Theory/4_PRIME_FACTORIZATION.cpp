#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

/* PRIME_FACTORIZATION */ void P_F(ll n);

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){
        ll a; cin >> a;
        P_F(a);
    }
}

//?----------------------------------------------------------------------------------------------


//*____________________________________PRIME_FACTORIZATION________________________________________

void P_F(ll n){
	int cnt=0;
	for(int i=2; i*i<=n; i++){
    	if(n%i == 0){
        	while(n%i == 0){
            	cnt++;
                n = n/i;
            }
            cout << i << "^" << cnt << " , ";
            cnt=0;
        }
    }
    if(n > 1) cout << n << "^" << 1 << endl;
    else cout << endl;
}

//*_______________________________________________________________________________________________