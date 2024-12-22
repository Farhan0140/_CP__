#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________

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
    DSU_Initialize(8);

    Union_by_Size(1, 2);
    Union_by_Size(2, 3);
    Union_by_Size(3, 4);

    Union_by_Level(5, 6);
    Union_by_Level(6, 7);

    cout << "Leader of 1 " << Find_Leader(1) << endl;
    cout << "Leader of 7 " << Find_Leader(7) << endl;
    Union_by_Level(1, 7);

    cout << "After Connect ""1, 7""\nLeader of 1 " << Find_Leader(1) << endl;
    cout << "Leader of 7 " << Find_Leader(7) << endl;
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