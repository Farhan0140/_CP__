#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int mod = 1e9 + 7;
const int S = 1e5;


//_______________________________________________________________________________________________

//     TC ---> O(n)

void optimized_approach() {
    ll n, q; 
    cin >> n >> q;
    vector<ll> main_array(n+1), prefix_array(n+2, 0), ans_array(n+1);

    main_array[0] = 0;
    prefix_array[0] = 0;
    ans_array[0] = 0;

    for(int i=1; i<=n; i++) {
        cin >> main_array[i];
    }

    while(q--) {         // TC   O(q)
        ll l, r, x;
        cin >> l >> r >> x;

        prefix_array[l] += x;
        prefix_array[r+1] -= x;
    }


    // Calculating Prefix -----> TC O(n)
    for(int i=1; i<=n; i++) {
        prefix_array[i] = prefix_array[i-1] + prefix_array[i];
    }   


    // Now adding the prefix to the main array --------> TC  O(n)
    for(int i=1; i<=n; i++) {
        ans_array[i] = prefix_array[i] + main_array[i];
    }
    

    for(int i=1; i<=n; i++) {
        cout << ans_array[i] << " ";
    }
    cout << endl;
}

//_______________________________________________________________________________________________


int main(){
    optimized_approach();
    return 0;
}


//_______________________________________________________________________________________________