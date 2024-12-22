#include <bits/stdc++.h>
using namespace std;

#define ll long long
//_______________________________________________________________________________________________

void Print_Divisors_Naive(ll n) {         // TC: O(N)
    for(int i=1; i<=n; i++) {
        if(n%i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}


void Print_Divisors_Optimize(ll n) {      // TC: O(sqrt(N))
    // vector<ll> arr;
    // for(int i=1; i<=sqrt(n); i++) {
    //     if(n%i == 0) {
    //         arr.push_back(i);
    //         arr.push_back(n/i);
    //     }
    // }

    // for(auto it: arr) {
    //     cout << it << " ";  // For [36] --> 1 2 3 4 6 6 9 12 18 36    // 6 6 appears in multiple time
    // }                       // Thats Why we use Set

    // OR: Using If statement..........

    // for(int i=1; i<=sqrt(n); i++) {
    //     if(n%i == 0) {
    //         arr.push_back(i);
            
    //         if((n/i) != i) {
    //             arr.push_back(n/i);
    //         }
    //     }
    // }
    // sort(arr.begin(), arr.end());



    set<ll> st;

    for(int i=1; i<=sqrt(n); i++) {             // for(int i=1; i*i <= n; i++)
        if(n%i == 0) {                          //          --> i = sqrt(n)
            st.insert(i);
            st.insert(n/i);
        }
    }

    for(auto it: st) {
        cout << it << " ";      // For [36] --> 1 2 3 4 6 9 12 18 36    // Now all values are unique
    }
    cout << endl;
}


void K_th_Divisors_Naive(ll n, ll k) {
    vector<ll> arr;

    for(ll i=1; i*i<=n; i++) {
        if(n%i == 0) {
            arr.push_back(i);

            if((n/i) != i) {
                arr.push_back(n/i);
            }
        }
    }

    sort(arr.begin(), arr.end());

    cout << arr[k] << endl;
}


//_______________________________________________________________________________________________


int main(){
    ll n; cin >> n;
    // Print_Divisors_Naive(n);

    // Print_Divisors_Optimize(n);

    K_th_Divisors_Naive(n, 4);
    return 0;
}


//_______________________________________________________________________________________________