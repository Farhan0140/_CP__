#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

// SEGMENTED_SIEVE {
        void Sieve(int R);
        void Segmented_Sieve(int L, int R);
// }

vector<int>v1;

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){
        ll left, right; cin >> left >> right;

        Sieve(right);
        Segmented_Sieve(left, right);
    }
}

//?----------------------------------------------------------------------------------------------


//*____________________________________SEGMENTED_SIEVE____________________________________________

void Sieve(int R){
    ll arr[R+5];
    memset(arr, 0, sizeof(arr));
    for(int i=2; i*i<=R; i++){
        if(arr[i] == 0){
            for(int j=i*i; j<=R; j+=i){
                arr[j] = 1;
            }
        }
    }

    for(int i=2; i<=R; i++){
        if(arr[i] == 0){
            v1.push_back(i);
        }
    }
}

void Segmented_Sieve(int L, int R){
    if(L == 1) L++;
    ll size = (R-L)+1;
    ll arr[size+1];
    memset(arr, 0, sizeof(arr));

    for(int p:v1){
        if(p*p <= R){
            ll g = (L/p)*p;
            if(g < L) g+=p;
            for(; g<=R; g+=p){
                if(g != p){
                    arr[g-L] = 1;
                }
            }
        }
    }

    for(int i=0; i<size; i++){
        if(arr[i] == 0){
            cout << i+L << " ";
        }
        cout << endl;
    }
    v1.clear();
}

//*_______________________________________________________________________________________________