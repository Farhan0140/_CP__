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

ll LCS(string a, ll a_l, string b, ll b_l);

const ll S = 1e2+5;
ll DP[S][S];

//_______________________________________________________________________________________________
 
 
int main(){
    IOS;
    string s, s1; cin >> s >> s1;

    for(int i=0; i<=s.length(); i++) {
        for(int j=0; j<=s1.length(); j++) {
            DP[i][j] = -1;
        }
    }

    ll lcs = LCS(s, s.length(), s1, s1.length());
    cout << lcs << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________

ll LCS(string a, ll a_l, string b, ll b_l) {
    if(a_l == 0 || b_l == 0) {
        return 0;
    }

    if(DP[a_l][b_l] != -1) {
        return DP[a_l][b_l];
    }

    if(a[a_l - 1] == b[b_l - 1]) {
        return DP[a_l][b_l] = LCS(a, a_l-1, b, b_l-1) + 1;
    } else {
        ll option_1 = LCS(a, a_l-1, b, b_l);
        ll option_2 = LCS(a, a_l, b, b_l-1);
        return DP[a_l][b_l] = max(option_1, option_2);
    }
}

//_______________________________________________________________________________________________