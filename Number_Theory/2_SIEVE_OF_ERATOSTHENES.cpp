#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

/* SIEVE_OF_ERATOSTHENES */ void S_O_E(ll n);

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();
    ll a;
    cin >> a;
    S_O_E(a);
}

//?----------------------------------------------------------------------------------------------


//*_________________________________SIEVE_OF_ERATOSTHENES________________________________________

void S_O_E(ll n){
	ll prime[n+3];       // declaring an array
    memset(prime, 0, sizeof(prime));     // Push the value 0 of all index, Let the value of all index be 0, means all index are prime
    
    for(int i=2; i*i<=n; i++){      // i*i<=n.   >> i<sqrt(n)
    	if(prime[i] == 0){     // if prime[i] == 0 that means this index is prime; if prime[i] == 1; that's means this index is not prime
        	for(int j=i*i; j<=n; j+=i){  // when i=2; j=2*2=4; j+=2= 6, 8, 10
            	prime[j] = 1;     // prime[j] = 1; means j th index is true and this index is not prime
            }
        }
    }
    
    for(int i=2; i<=n; i++){
    	if(prime[i] != 1){     //If the value of index is not 1, then that index is prime
        	cout << i << " ";
        }
    }
}

//*_______________________________________________________________________________________________