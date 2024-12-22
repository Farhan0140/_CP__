#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________

/*
4
1 2 4 6
7
*/

#define ll long long int
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//_______________________________________________________________________________________________

 
 
int main(){
    fast_read();
    ll n; cin >> n;
    ll Arr[n+5];

    for(int i=0; i<n; i++) {
        cin >> Arr[i];
    }

    ll sum; cin >> sum;

    bool DP[n+5][sum+5];

    for(int i=0; i<=sum; i++) {
        DP[0][i] = false;
    }
    DP[0][0] = true;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(Arr[i-1] <= j) {
                bool Option_1 = DP[i-1][j-Arr[i-1]];
                bool Option_2 = DP[i-1][j];
                DP[i][j] = Option_1 || Option_2;

                // DP[i][j] = DP[i-1][j-Arr[i-1]] || DP[i-1][j];
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    if(DP[n][sum]) {
        cout << "Yes, It's Possible" << endl;
    } else {
        cout << "No, It's Not Possible" << endl;
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________