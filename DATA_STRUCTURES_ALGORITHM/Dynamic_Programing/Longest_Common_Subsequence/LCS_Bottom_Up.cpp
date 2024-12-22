#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________
/*
abcdfgr
acfdgr
---> 5
*/
#define ll long long int
#define IOS (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//_______________________________________________________________________________________________
 
 
int main(){
    IOS;
    string a, b; cin >> a >> b;
    ll a_l = a.length(), b_l = b.length();
    ll DP[a_l+5][b_l+5];

    for(int i=0; i<=a_l; i++) {
        for(int j=0; j<=b_l; j++) {
            if(i==0 || j==0) { DP[i][j] = 0; }
        }
    }

    for(int i=1; i<=a_l; i++) {
        for(int j=1; j<=b_l; j++) {
            if(a[i-1] == b[j-1]) {
                DP[i][j] = DP[i-1][j-1] + 1;
            } else {
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }

    cout << DP[a_l][b_l] << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________