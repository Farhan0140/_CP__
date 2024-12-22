#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________

/*
4
1 2 4 6
7
*/

#define ll long long int
#define all(x) x.begin(),x.end()
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));
 
//_______________________________________________________________________________________________

const ll S = 1e2+5;
bool Subset_Sum(ll n, ll s, ll Arr[]);
int DP[S][S];

//_______________________________________________________________________________________________

 
 
int main(){
    fast_read();
    ll n; cin >> n;
    ll Arr[n+5];

    for(int i=0; i<n; i++) {
        cin >> Arr[i];
    }

    ll sum; cin >> sum;

    memset(DP, -1, sizeof(DP));

    // bool is_found = Subset_Sum(n, sum, Arr);

    if(Subset_Sum(n, sum, Arr)) {
        cout << "Yes, It's Possible" << endl;
    } else {
        cout << "No, It's Not Possible" << endl;
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________

bool Subset_Sum(ll n, ll s, ll Arr[]) {
    if(n == 0) {
        if(s == 0) {
            return true;
        } else {
            return false;
        }
    }

    if(DP[n][s] != -1) {
        return DP[n][s];
    }

    if(Arr[n-1] <= s) {
        bool Option_1 = Subset_Sum(n-1, s-Arr[n-1], Arr);
        bool Option_2 = Subset_Sum(n-1, s, Arr);
        return DP[n][s] = (Option_1 || Option_2);
    } else {
        return DP[n][s] = Subset_Sum(n-1, s, Arr);
    }
}

//_______________________________________________________________________________________________