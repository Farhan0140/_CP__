#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

/*
5
1 2 3 1 2
1

--> 5
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

    ll diff; cin >> diff;

    if((diff + sum) % 2 != 0) {
        cout << "There is no way to Count the Subset Sum With a Given Difference\n";
        return 0;
    }

    ll s_1 = (diff + sum) / 2;
    ll DP[n+5][s_1+5];

    DP[0][0] = 1;
    for(int i=1; i<=s_1; i++) { DP[0][i] = 0; }

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=s_1; j++) {
            if(Arr[i-1] <= j) {
                DP[i][j] = DP[i-1][j - Arr[i-1]] + DP[i-1][j];
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    cout << DP[n][s_1] << endl;
    return 0;
}


//_______________________________________________________________________________________________