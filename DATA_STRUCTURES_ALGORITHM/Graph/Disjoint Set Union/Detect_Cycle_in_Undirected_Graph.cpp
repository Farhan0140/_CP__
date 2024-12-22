#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________

/*
4 3
0 1
1 2
2 3
*/

#define ll long long int
#define all(x) x.begin(),x.end()
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

const ll S = 1e5+5;
ll parent[S];
ll Group_Size[S];
ll Level[S];

void DSU_Initialize(ll src);
ll Find_Leader(ll node);
void Union_by_Size(ll node1, ll node2);
void Union_by_Level(ll node1, ll node2);

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    ll n, e; cin >> n >> e;
    bool is_cycle = false;
    
    DSU_Initialize(n);

    while(e--) {
        ll u, v; cin >> u >> v;
        ll Leader_U = Find_Leader(u);
        ll Leader_V = Find_Leader(v);

        if(Leader_U == Leader_V) {
            is_cycle = true;
        } else {
            Union_by_Size(u, v);
            // Union_by_Level(u, v);
        }
    }

    (is_cycle)? cout << "Cycle Found" << endl : cout << "Cycle Not Found";
    return 0;
}
 
 
//_______________________________________________________________________________________________

void DSU_Initialize(ll src) {
    for(int i=0; i<src; i++) {
        parent[i] = -1;
        Group_Size[i] = 1;
        Level[i] = 0;
    }
}

ll Find_Leader(ll node) {
    if(parent[node] == -1) { return node; }
    return parent[node] = Find_Leader(parent[node]);
}

void Union_by_Size(ll node1, ll node2) {
    ll Leader_A = Find_Leader(node1);
    ll Leader_B = Find_Leader(node2);

    if(Group_Size[Leader_A] > Group_Size[Leader_B]) {
        parent[Leader_B] = Leader_A;
        Group_Size[Leader_A] += Group_Size[Leader_B];
    } else {
        parent[Leader_A] = Leader_B;
        Group_Size[Leader_B] += Group_Size[Leader_A];
    }
}

void Union_by_Level(ll node1, ll node2) {
    ll Leader_A = Find_Leader(node1);
    ll Leader_B = Find_Leader(node2);

    if(Level[Leader_A] > Level[Leader_B]) {
        parent[Leader_B] = Leader_A;
    } else if(Level[Leader_B] > Level[Leader_A]) {
        parent[Leader_A] = Leader_B;
    } else {
        parent[Leader_A] = Leader_B;
        Level[Leader_B]++;
    }
}

//_______________________________________________________________________________________________