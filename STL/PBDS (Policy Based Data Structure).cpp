/*
In PBDS we can use every function of set and multiset, But there are two extra functions in PBDS

1. Order of key(x) --> It returns how many values are strictly less than x  --> TC O(logn) 
2. find by order(ind) ---> it returns the value of the index of ind  ---> TC O(logn)

*/


#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

//                                           for set: less<T>
//                                     for multi_set: less_equal<T>
template <typename T> using pbds = tree<T, null_type, less<T>,      rb_tree_tag, tree_order_statistics_node_update>;

//_______________________________________________________________________________________________


#define ll long long int

//_______________________________________________________________________________________________


int main(){
    ll n; 
    cin >> n;

// Input:

    pbds<ll> pd;

    for(int i=0; i<n; i++) {
        ll x; 
        cin >> x;         // 10
                          // 1 7 2 9 3 5 8 2 2 2
        pd.insert(x);
    }

// Output

    for(auto it: pd) {
        cout << it << " "; // 1 2 3 5 7 8 9 -> Like Set
    }                      // 1 2 2 2 2 3 5 7 8 9 ->  like multi_set
    return 0;
}


//_______________________________________________________________________________________________