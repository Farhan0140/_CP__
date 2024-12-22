#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

/* MODULAR_ARITHMETIC */ void MOD(string s, ll m);

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){
        string s;
        int m;
        cin >> s >> m;
        MOD(s, m);
    }
}

//?----------------------------------------------------------------------------------------------


//*____________________________________MODULAR_ARITHMETIC________________________________________

void MOD(string s, ll m){
    ll ans = 0;
    for(int i=0; i<s.length(); i++){
        ans = ans * 10 + (s[i] - '0');
        ans = ans % 10;
    }
    if((ans%m) == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

//*_______________________________________________________________________________________________