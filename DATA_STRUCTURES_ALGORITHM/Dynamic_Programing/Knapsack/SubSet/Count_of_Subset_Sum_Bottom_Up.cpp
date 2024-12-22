#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________

/*
4
1 2 4 6
7

6
0 0 0 0 0 7
7

//-----> 16
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

    int DP[n+5][sum+5];

    // for(int i=0; i<=sum; i++) {
    //     DP[0][i] = 0;
    // }
    memset(DP, 0, sizeof(DP));
    DP[0][0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(Arr[i-1] <= j) {
                int Option_1 = DP[i-1][j-Arr[i-1]];
                int Option_2 = DP[i-1][j];
                DP[i][j] = Option_1 + Option_2;

                // DP[i][j] = DP[i-1][j-Arr[i-1]] || DP[i-1][j];
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    cout << "Number's Of Subset Sum: " << DP[n][sum] << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________