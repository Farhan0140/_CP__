#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________
/*
4 6
5 3 2 4
4 1 3 2

----> 18
*/

#define let long long int
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));
//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    let n, knapsack; cin >> n >> knapsack;
    let weight[n+5], value[n+5];

    for(let i=0; i<n; i++) { cin >> value[i]; }
    for(let i=0; i<n; i++) { cin >> weight[i]; }

    let DP[n+5][knapsack+5];

    for(let i=0; i<=n; i++) {
        for(let j=0; j<=knapsack; j++) {
            if(i==0 || j==0) {
                DP[i][j] = 0;
            }
        } 
    }

    for(let i=1; i<=n; i++) {
        for(let j=1; j<=knapsack; j++) {
            if(weight[i-1] <= j) {
                let option_1 = DP[i][j - weight[i-1]] + value[i-1];
                let option_2 = DP[i-1][j];

                DP[i][j] = max(option_1, option_2);
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    cout << DP[n][knapsack] << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________