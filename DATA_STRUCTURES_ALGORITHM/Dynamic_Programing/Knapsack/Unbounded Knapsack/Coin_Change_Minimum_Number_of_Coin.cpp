#include <bits/stdc++.h>
using namespace std;

// Count Subset Sum i eita
//_______________________________________________________________________________________________
/*
3
1 2 3
5

--> 2 
*/
#define let long long int
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    let n; cin >> n;
    let coin_weight[n+5];
    for(let i=0; i<n; i++) {
        cin >> coin_weight[i];
    }
    let coin; cin >> coin;
    int DP[n+5][coin+5];

    for(int i=0; i<=coin; i++) {
        DP[0][i] = INT_MAX - 1;
    }
    DP[0][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=coin; j++) {
            if(coin_weight[i-1] <= j) {
                int Option_1 = DP[i][j-coin_weight[i-1]] + 1;
                int Option_2 = DP[i-1][j];
                DP[i][j] = min(Option_1, Option_2);
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    cout << DP[n][coin] << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________