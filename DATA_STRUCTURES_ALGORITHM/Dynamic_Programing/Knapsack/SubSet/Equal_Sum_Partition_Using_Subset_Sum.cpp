#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

/*
5
1 2 4 6 5
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

    if(sum % 2 != 0) {
        cout << "There is no way make both Subset equal" << endl;
        return 0;
    }

    ll Sum = sum / 2;
    bool DP[n+5][Sum+5];
    DP[0][0] = true;
    for(int i=1; i<=Sum; i++) { DP[0][i] = false; }
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=Sum; j++) {
            if(Arr[i-1] <= j) {
                DP[i][j] = DP[i-1][j - Arr[i-1]] || DP[i-1][j];
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }
    
    if(DP[n][Sum]) {
        cout << "Yes, It's possible to make both Subset equal" << endl;
    } else {
        cout << "There is no way make both Subset equal" << endl;
    }
    return 0;
}


//_______________________________________________________________________________________________