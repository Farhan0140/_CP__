#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

/*
4
1 5 4 11

--> 1
*/

#define ll long long int
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//_______________________________________________________________________________________________



int main(){
    fast_read();
    ll n; cin >> n;
    ll Arr[n+5];
    ll sum = 0;

    for(int i=0; i<n; i++) {
        cin >> Arr[i];
        sum += Arr[i];
    }

    bool DP[n+5][sum+5];
    DP[0][0] = true;
    for(int i=1; i<=sum; i++) { DP[0][i] = false; }
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(Arr[i-1] <= j) {
                DP[i][j] = DP[i-1][j - Arr[i-1]] || DP[i-1][j];
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }
    
    vector<ll> All_Sum;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(DP[i][j] == 1) {
                All_Sum.push_back(j);
            }
        }
    }

    ll min_diff = INT_MAX;

    for(auto val: All_Sum) {
        ll s1 = val;
        ll s2 = sum - val;
        min_diff = min(min_diff, abs(s1 - s2));
    }

    cout << min_diff << endl;
    return 0;
}


//_______________________________________________________________________________________________