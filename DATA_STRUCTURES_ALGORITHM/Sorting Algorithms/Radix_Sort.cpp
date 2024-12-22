#include <bits/stdc++.h>
using namespace std;

// Time Complexity ---> O(  D    * (N+R))
//                        Digits   Count Sort
//_______________________________________________________________________________________________

/*
6
785 200 384 65 87 2
*/
#define ll long long int
#define IOS (ios_base :: sync_with_stdio(false), cin.tie(NULL));

void Radix_Sort(ll arr[], ll s, ll mx);

//_______________________________________________________________________________________________
 
 
int main(){
    IOS;
    ll n; cin >> n;
    ll arr[n+5];
    ll mx = INT_MIN;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    Radix_Sort(arr, n, mx);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________

void Radix_Sort(ll arr[], ll s, ll mx) {
    ll tmp[s+5], cnt[10], prefix[10];
    ll for_loop = mx;

    ll pos = 1;
    while(for_loop > 0) {
        memset(cnt, 0, sizeof(cnt));
        memset(prefix, 0, sizeof(prefix));

        for(int i=0; i<s; i++) {
            cnt[(arr[i]/pos) % 10]++;
        }

        prefix[0] = cnt[0];
        for(int i=1; i<10; i++) {
            prefix[i] = cnt[i] + prefix[i-1];
        }

        for(int i=s-1; i>=0; i--) {
            ll index = --prefix[(arr[i]/pos) % 10];
            tmp[index] = arr[i];
        }

        for(int i=0; i<s; i++) {
            arr[i] = tmp[i];
        }

        for_loop /= 10;
        pos *= 10;
    }
}

//_______________________________________________________________________________________________