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

int Subset_Sum(ll n, ll s, ll Arr[]);

//_______________________________________________________________________________________________

 
 
int main(){
    fast_read();
    ll n; cin >> n;
    ll Arr[n+5];

    for(int i=0; i<n; i++) {
        cin >> Arr[i];
    }

    ll sum; cin >> sum;

    cout << "Number's Of Subset Sum: " << Subset_Sum(n, sum, Arr) << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________

int Subset_Sum(ll n, ll s, ll Arr[]) {
    if(n == 0) {
        if(s == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    if(Arr[n-1] <= s) {
        int Option_1 = Subset_Sum(n-1, s-Arr[n-1], Arr);
        int Option_2 = Subset_Sum(n-1, s, Arr);
        return (Option_1 + Option_2);
    } else {
        return Subset_Sum(n-1, s, Arr);
    }
}

//_______________________________________________________________________________________________