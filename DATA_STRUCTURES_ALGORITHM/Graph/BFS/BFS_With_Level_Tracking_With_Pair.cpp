#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________
 
#define ll long long int
#define all(x) x.begin(),x.end()

#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));
 
//_______________________________________________________________________________________________

const ll S = 1e5;
vector<ll> Arr[S];
bool visited[S];

void BFS(ll src, ll dis);

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    
    ll n, e; cin >> n >> e;
    while(e--) {
        int u, v; cin >> u >> v;
        Arr[u].push_back(v);
        Arr[v].push_back(u); // For Undirected Graph
    }

    memset(visited, false, sizeof(visited));

    ll src, dis; cin >> src >> dis;
    BFS(src, dis);
    return 0;
}
 
 
//_______________________________________________________________________________________________

void BFS(ll src, ll dis){
    queue<pair<ll, ll>> q; // Source, Level

    q.push({src, 0});
    visited[src] = true;
    bool is_connected = false;

    while(!q.empty()) {
        pair<ll, ll> parent = q.front(); q.pop();

        // cout << parent.first << " --> " << parent.second << endl;
        if(parent.first == dis) {
            is_connected = true;
        }

        for(ll child : Arr[parent.first]) {
            if(!visited[child]) {
                visited[child] = true;
                q.push({child, parent.second});
            }
        }
    }

    if(!is_connected) {
        cout << "Not Connected" << endl;
    } else {
        cout << "Connected" << endl;
    }
}

//_______________________________________________________________________________________________