#include <bits/stdc++.h>
using namespace std;

#define ll int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

// MATRIX_EXPONENTIATION {
        #define Size 200
        void Power_Matrix(ll A[][Size], ll n, ll p);
        void multiplication(ll A[][Size], ll B[][Size], ll n);
// }

ll M_Matrix[Size][Size], Result[Size][Size];

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();
    
    while(true){
        ll matrixSize, power; cin >> matrixSize >> power;
        ll arr[matrixSize][matrixSize];

        for(int i=1; i<=matrixSize; i++){
            for(int j=1; j<=matrixSize; j++){
                cin >> M_Matrix[i][j];
            }
        }

        Power_Matrix(M_Matrix, matrixSize, power);

        for(int i=1; i<=matrixSize; i++){
            for(int j=1; j<=matrixSize; j++){
                cout << M_Matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}

//?----------------------------------------------------------------------------------------------


//*____________________________________MATRIX_EXPONENTIATION______________________________________


void multiplication(ll A[][Size], ll B[][Size], ll n){
    ll res[n+1][n+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            res[i][j]=0;
            for(int k=1; k<=n; k++){
                ll x = (A[i][k] * B[k][j]);
                res[i][j] = (res[i][j]+x);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            A[i][j] = res[i][j];
        }
    }
}

void Power_Matrix(ll A[][Size], ll n, ll p){
    for(int i=1; i<=n; i++){                    //
        for(int j=1; j<=n; j++){                //
            if(i == j){                         //
                Result[i][j] = 1;               // This Nested loop Using for making Result Diagonally 1, and other index 0
            }else{                              // Because, if we multiply A matrix with this Result, This Matrix Value will not change ,,
                Result[i][j] = 0;               //
            }                                   //
        }                                       //
    }
    
    while(p){
        if(p%2 != 0){
            multiplication(Result, A, n);
            p--;
        }else{
            multiplication(A, A, n);
            p /= 2;
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            A[i][j] = Result[i][j];
        }
    }
}

//*_______________________________________________________________________________________________