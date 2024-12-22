#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________

/*
5 6
1 2 2
1 4 1
2 5 5
2 3 4
5 3 1
4 3 3
*/

#define ll long long int
#define all(x) x.begin(),x.end()

#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

const ll INF = 1e18;
const int S = 1e5+5;

//        node, Weight [Node]
vector<pair<ll, ll>> Arr[S];
ll Dis[S];
bool Vis[S];
ll Parents[S];

void Dijkstra(ll src);

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    ll n, e; cin >> n >> e;
    while(e--) {
        ll u, v, c; cin >> u >> v >> c;
        Arr[u].push_back({c, v});
        Arr[v].push_back({c, u});
    }

    for(int i=1; i<=n; i++) {
        Dis[i] = INF;
    }

    memset(Vis, false, sizeof(Vis));

    int src; cin >> src;
    Dijkstra(src);

    if(!Vis[n]) {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> Parent;
    ll x = n;

    while(true) {
        Parent.push_back(x);
        if(x == 1) { break; }
        x = Parents[x];
    }

    reverse(all(Parent));

    for(auto it: Parent) {
        cout << it << " ";
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________

void Dijkstra(ll src) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    Dis[src] = 0;
    Vis[src] = true;

    while(!pq.empty()) {
        pair<ll, ll> parent = pq.top(); pq.pop();
        ll p_node = parent.second;  // Parent Node
        ll p_cost = parent.first; // Parent Cost
        Vis[p_node] = true;

        for(pair<ll, ll> child: Arr[p_node]) {
            ll c_node = child.second;  // Child Node
            ll c_cost = child.first; // Child Cost

            if(Dis[p_node] + c_cost < Dis[c_node]) {
                Dis[c_node] = Dis[p_node] + c_cost;
                pq.push({Dis[c_node], c_node});
                Parents[c_node] = p_node;
            }
        }
    }
}

//_______________________________________________________________________________________________