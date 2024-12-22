#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________

/*
12
2 3 15 16 17 1 4 6 8 9 5 10
*/
#define ll long long int
#define IOS (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//_______________________________________________________________________________________________

void Merge(ll arr[], ll left, ll mid, ll right);
void Merge_Sort(ll arr[], ll left, ll right);

//_______________________________________________________________________________________________
 
 
int main(){
    IOS;
    ll n; cin >> n;
    ll arr[n+5];

    for(int i=0; i<n; i++) { cin >> arr[i]; }

    Merge_Sort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________

void Merge_Sort(ll arr[], ll left, ll right) {
    if(left < right) {
        ll mid = (left+right) / 2;
        Merge_Sort(arr, left, mid);
        Merge_Sort(arr, mid+1, right);
        Merge(arr, left, mid, right);
    }
}

//_______________________________________________________________________________________________

void Merge(ll arr[], ll left, ll mid, ll right) {
    ll left_size = mid - left + 1;
    ll right_size = right - mid;
    ll copy_left[left_size], copy_right[right_size];
    ll k = 0;

    for(int i=left; i<=mid; i++) {
        copy_left[k] = arr[i];
        k++;
    }

    k = 0;
    for(int i=mid+1; i<=right; i++) {
        copy_right[k] = arr[i];
        k++;
    }

    ll l_ptr = 0, r_ptr = 0;  // left, right Pointer
    ll cur = left; // current

    while(l_ptr < left_size && r_ptr < right_size) {
        if(copy_left[l_ptr] <= copy_right[r_ptr]) {
            arr[cur] = copy_left[l_ptr];
            l_ptr++; cur++;
        } else {
            arr[cur] = copy_right[r_ptr];
            r_ptr++; cur++;
        }
        // Or cur++;
    }

    while(l_ptr < left_size) {
        arr[cur] = copy_left[l_ptr];
        l_ptr++; cur++;
    }
    while(r_ptr < right_size) {
        arr[cur] = copy_right[r_ptr];
        r_ptr++; cur++;
    }
}

//_______________________________________________________________________________________________