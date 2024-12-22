#include <bits/stdc++.h>
using namespace std;

// Count Subset Sum i eita
//_______________________________________________________________________________________________
/*
3
1 2 3
5

--> 5
*/
#define let long long int
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    let n; cin >> n;
    let weight[n+5];
    for(let i=0; i<n; i++) {
        cin >> weight[i];
    }
    let sum; cin >> sum;
    int DP[n+5][sum+5];

    for(int i=0; i<=sum; i++) {
        DP[0][i] = 0;
    }
    DP[0][0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(weight[i-1] <= j) {
                int Option_1 = DP[i][j-weight[i-1]];
                int Option_2 = DP[i-1][j];
                DP[i][j] = Option_1 + Option_2;

                // DP[i][j] = DP[i-1][j-Arr[i-1]] || DP[i-1][j];
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    cout << DP[n][sum] << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________