#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

/* PRIMALITY_TEST */ bool P_T(ll n);

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();
    while(true){
        ll a; cin >> a;
        bool bl = P_T(a);
        if(bl == true){
            cout << a << "is Prime Number" << endl;
        }else{
            cout << a << "is Not Prime Number" << endl;
        }
    }
}

//?----------------------------------------------------------------------------------------------


//*____________________________________PRIMALITY_TEST_____________________________________________

bool P_T(ll n){
	if(n < 2) return false;       // 0 and 1 is not a prime number
    if(n <= 3) return true;         // 2 and 3 is prime number
    if(n%2 == 0) return false;        // We know, all even number is not prime number except 2, because all even number are divisible by 2
    for(int i=3; i<=sqrt(n); i+=2){      // Since, all even number are not prime number, except 2, so we need to check just all odd numbers
    	if(n%i == 0) return false;       
    }
    return true;
}
//*_______________________________________________________________________________________________