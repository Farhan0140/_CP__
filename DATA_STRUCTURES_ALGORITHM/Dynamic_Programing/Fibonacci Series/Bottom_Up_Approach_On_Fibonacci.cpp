#include <bits/stdc++.h>
using namespace std;

// nth Fibonacci Number
// Time Complexity O(n)

//_______________________________________________________________________________________________

#define ll long long int
#define all(x) x.begin(),x.end()
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

const ll S = 1e5+5;
ll DP[S];

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    memset(DP, -1, sizeof(DP));
    ll n; cin >> n;

    DP[0] = 0;
    DP[1] = 1;

    for(int i=2; i<=n; i++) {
        DP[i] = DP[i-1] + DP[i-2];
    }

    cout << DP[n] << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________