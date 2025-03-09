#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int SZ = 1e5 + 9;  


//_______________________________________________________________________________________________

ll arr[SZ], Tree[4 * SZ];

void Build (ll Node, ll Begin, ll End) {

    if(Begin == End) {

        Tree[Node] = arr[Begin];   // OR arr[End];
        return;

    }

    ll Mid = (Begin + End) / 2;
    ll Left_Child = 2 * Node;
    ll Right_Child = (2 * Node) + 1;

    Build(Left_Child, Begin, Mid);
    Build(Right_Child, Mid + 1, End);

}

//_______________________________________________________________________________________________


int main(){

    ll n, q; cin >> n >> q;
    for(int i=1; i<=n; i++) {

        cin >> arr[i];

    }
    return 0;
}


//_______________________________________________________________________________________________