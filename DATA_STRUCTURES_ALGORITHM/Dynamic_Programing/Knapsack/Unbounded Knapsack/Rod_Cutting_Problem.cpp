#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________
/*
8
2 4 4 5 8 10 12 9

---> 16
*/
#define ll long long int
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

ll Unbounded_Knapsack(ll n, ll s, ll weight[], ll value[]);

const ll S = 2e2+5;
ll DP[S][S];

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    ll n; cin >> n; // Rod Size
    ll value[n+5];  // Per meter Profit
    ll weight[n+5];
    for(int i=0; i<n; i++) { 
        cin >> value[i];
        weight[i] = i+1;
    }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            DP[i][j] = -1;
        }
    }

    ll Maximum_Profit = Unbounded_Knapsack(n, n, weight, value);
    cout << Maximum_Profit << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________

ll Unbounded_Knapsack(ll n, ll s, ll weight[], ll value[]) {
    if(n==0 || s==0) {
        return 0;
    }

    if(DP[n][s] != -1) {
        return DP[n][s];
    }
    
    if(weight[n-1] <= s) {
        ll option_1 = Unbounded_Knapsack(n, s - weight[n-1], weight, value) + value[n-1];
        ll option_2 = Unbounded_Knapsack(n-1, s, weight, value);

        return DP[n][s] = max(option_1, option_2);
    } else {
        return DP[n][s] = Unbounded_Knapsack(n-1, s, weight, value);
    }
}

//_______________________________________________________________________________________________