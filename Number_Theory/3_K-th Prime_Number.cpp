#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

int Prime[90000001];      //If we declare an array globally. It's auto initialize value 0 in all indexes, don't need to use memset
int KK = 90000000;
vector<int>primes;        // All prime numbers are stored in this vector

/* K-th Prime_Number */ void K_P();

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    K_P();

    while(true){
        ll a; cin >> a;
        cout << primes[a-1] << endl;
    }
}

//?----------------------------------------------------------------------------------------------


//*_____________________________________K-th Prime_Number________________________________________

void K_P(){
    for(int i=2; i*i<=KK; i++){
    	if(Prime[i] == false){
        	for(int j=i*i; j<=KK; j+=i){
            	Prime[j] = true;
            }
        }
    }
    
    for(int i=2; i<=KK; i++){
    	if(Prime[i] == false){
        	primes.push_back(i);
        }
    }
}

//*_______________________________________________________________________________________________