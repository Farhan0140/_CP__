#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

// 0 1 1 2 3 5 8 13 21 34 55 ...........
// 0 1 2 3 4 5 6  7  8  9 10 .... index ....

//!-----------------------------------------------------------------------------------------------

// FIBONACCI_FINDING_using_MATRIX_EXPONENTIATION {
        #define fs 5
        void FibMul(ll A[][fs], ll B[][fs]);
        void FibSolve(ll a, ll b, ll power);
// }

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){
        ll firstNumber=0, secondNumber=1, k_th_num; cin >> k_th_num;
        FibSolve(firstNumber, secondNumber, k_th_num);
    }
}

//?----------------------------------------------------------------------------------------------


//*__________________FIBONACCI_FINDING_using_MATRIX_EXPONENTIATION_______________________________

ll FibBase[fs][fs], FibResult[fs][fs];

void FibMul(ll A[][fs], ll B[][fs]){
    ll res[3][3];
    for(ll i=0; i<2; i++){
        for(ll j=0; j<2; j++){
            res[i][j] = 0;
            for(ll k=0; k<2; k++){
                ll x = (A[i][k] * B[k][j]);
                res[i][j] = (res[i][j]+x);
            }
        }
    }
    
    for(ll i=0; i<2; i++){
        for(ll j=0; j<2; j++){
            A[i][j] = res[i][j];
        }
    }
}

void FibSolve(ll a, ll b, ll power){
    FibBase[0][0] = 0;
    FibBase[0][1] = FibBase[1][0] = FibBase[1][1] = 1;
    
    FibResult[0][1] = FibResult[1][0] = 0;
    FibResult[0][0] = FibResult[1][1] = 1;
    
    power--;
    
    while(power){
        if(power%2 == 1){
            FibMul(FibResult, FibBase);
            power--;
        }else{
            FibMul(FibBase, FibBase);
            power /= 2;
        }
    }
    
    ll ans = a * FibResult[0][1] + b * FibResult[1][1];
    cout << ans << endl;
}

//*_______________________________________________________________________________________________