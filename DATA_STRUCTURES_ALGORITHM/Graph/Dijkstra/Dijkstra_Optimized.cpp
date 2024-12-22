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

void Dijkstra(ll src);
 
//_______________________________________________________________________________________________

class Cmp{
    public:
      bool operator()(pair<ll, ll> a, pair<ll, ll> b) {
          return (a.second > b.second);
      }
};

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    ll n, e; cin >> n >> e;
    while(e--) {
        ll u, v, c; cin >> u >> v >> c;
        Arr[u].push_back({v, c});
        Arr[v].push_back({u, c});
    }

    for(int i=1; i<=n; i++) {
        Dis[i] = INF;
    }

    int src; cin >> src;
    Dijkstra(src);

    for(int i=1; i<=n; i++) {
        cout << i << " --> " << Dis[i] << endl;
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________

void Dijkstra(ll src) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Cmp> pq;
    pq.push({src, 0});
    Dis[src] = 0;

    while(!pq.empty()) {
        pair<ll, ll> parent = pq.top(); pq.pop();
        ll p_node = parent.first;  // Parent Node
        ll p_cost = parent.second; // Parent Cost

        for(pair<ll, ll> child: Arr[p_node]) {
            ll c_node = child.first;  // Child Node
            ll c_cost = child.second; // Child Cost

            if(p_cost + c_cost < Dis[c_node]) {
                Dis[c_node] = p_cost + c_cost;
                pq.push({c_node, Dis[c_node]});
            }
        }
    }
}

//_______________________________________________________________________________________________