#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int S = 1e5;


//_______________________________________________________________________________________________


// আমাকে একটা array এবং কিছু querie দেওয়া হবে,, আমাকে array টা আপডেট করে প্রিন্ট করতে হবে,, 
// querie তে left right এবং x দেওয়া থাকবে,, array তে left to right প্রতিটা index এর সাথে x যোগ করতে হবে

// Brute Force Approach        TC ---> O(n^2)

void brute_force_approach() {
    ll n, q; 
    cin >> n >> q;
    vector<ll> main_array(n+1);

    for(int i=0; i<n; i++) {
        cin >> main_array[i];
    }

    while(q--) {
        ll l, r, x;
        cin >> l >> r >> x;

        for(int i=l; i<r; i++) {
            main_array[i] += x;
        }
    }

    for(int i=0; i<n; i++) {
        cout << main_array[i] << " ";
    }
    cout << endl;
}


//_______________________________________________________________________________________________


int main(){
    brute_force_approach();  //   TC ---> O(n^2)
    return 0;
}


//_______________________________________________________________________________________________