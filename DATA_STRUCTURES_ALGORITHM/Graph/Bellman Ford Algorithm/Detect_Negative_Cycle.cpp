#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int

//_______________________________________________________________________________________________

/*
4 4
0 3 12
1 3 3
2 1 2
0 2 5

3 3
0 1 -2
1 2 1
2 0 -3
*/

class Edge_List{
    public:
    ll u, v, w;

    Edge_List(ll u, ll v, ll w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

//_______________________________________________________________________________________________

#define all(x) x.begin(),x.end()
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

const ll INF = 1e18;
const int S = 1e5+5;

ll Dis[S];

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    ll n, e; cin >> n >> e;

    vector<Edge_List> edges;
    while(e--) {
        ll u, v, w; cin >> u >> v >> w;
        edges.push_back(Edge_List(u, v, w));
    }

    for(int i=0; i<n; i++) {
        Dis[i] = INF;
    }

    int src = 0;
    Dis[src] = 0;

    for(int i=1; i<=n-1; i++) {
        for(Edge_List edl: edges) {
            ll u = edl.u;
            ll v = edl.v;
            ll w = edl.w;

            if(Dis[u] < INF && Dis[u] + w < Dis[v]) {
                Dis[v] = Dis[u] + w;
            }
        }
    }

    bool is_cycle = false;

    for(Edge_List edl: edges) {
        ll u = edl.u;
        ll v = edl.v;
        ll w = edl.w;

        if(Dis[u] < INF && Dis[u] + w < Dis[v]) {
            is_cycle = true;
        }
    }

    if(is_cycle) {
        cout << "Cycle Found! There is no Answer" << endl;
        return 0;
    }
    for(int i=0; i<n; i++) {
        cout << i << " --> " << Dis[i] << endl;
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________