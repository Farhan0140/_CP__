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

let Unbounded_Knapsack(let n, let s, let weight[], let value[]);

const let S = 2e3+5;
let DP[S][S];

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    let n, knapsack; cin >> n >> knapsack;
    let weight[n+5], value[n+5];

    for(let i=0; i<n; i++) { cin >> value[i]; }
    for(let i=0; i<n; i++) { cin >> weight[i]; }
    memset(DP, -1, sizeof(DP));

    let Max = Unbounded_Knapsack(n, knapsack, weight, value);

    cout << Max << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________

let Unbounded_Knapsack(let n, let s, let weight[], let value[]) {
    if(n==0 || s==0) {
        return 0;
    }

    if(DP[n][s] != -1) {
        return DP[n][s];
    }
    
    if(weight[n-1] <= s) {
        let option_1 = value[n-1] + Unbounded_Knapsack(n, s - weight[n-1], weight, value);
        let option_2 = Unbounded_Knapsack(n-1, s, weight, value);

        return DP[n][s] = max(option_1, option_2);
    } else {
        return DP[n][s] = Unbounded_Knapsack(n-1, s, weight, value);
    }
}

//_______________________________________________________________________________________________