#include <bits/stdc++.h>
using namespace std;
 
// Time Complexity ---> O(N + R)

//_______________________________________________________________________________________________

/*
11
0 1 2 1 1 3 3 0 1 1 4
*/

#define ll long long int
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));
void Counting_Sort(ll arr[], ll s, ll mx);

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    ll n; cin >> n;
    ll arr[n+1];
    ll mx = INT_MIN;
    
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    
    Counting_Sort(arr, n, mx);
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________

void Counting_Sort(ll arr[], ll s, ll mx) {
    ll cnt[mx+5], prefix[mx+5];
    memset(cnt, 0, sizeof(cnt));
    memset(prefix, 0, sizeof(prefix));
    
    for(int i=0; i<s; i++) {
        cnt[arr[i]]++;
    }
    
    prefix[0] = cnt[0];
    for(int i=1; i<=mx; i++) {
        prefix[i] = cnt[i] + prefix[i-1];
    }
    
    ll old_arr[s+5];
    for(int i=0; i<s; i++) {
        old_arr[i] = arr[i];
    }
    
    for(int i=s-1; i>=0; i--) {
        ll index = --prefix[old_arr[i]];
        arr[index] = old_arr[i];
    }
}

//_______________________________________________________________________________________________