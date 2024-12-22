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
ll level[S];

void BFS(ll src);

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
    memset(level, -1, sizeof(level));

    ll src; cin >> src;
    BFS(src);

    for(ll i=0; i<n; i++) {
        cout << i << " -> " << level[i] << endl;
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________

void BFS(ll src){
    queue<ll> q;

    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while(!q.empty()) {
        ll parent = q.front(); q.pop();

        cout << parent << " ";

        for(ll child : Arr[parent]) {
            if(!visited[child]) {
                visited[child] = true;
                q.push(child);
                level[child] = level[parent] + 1;
            }
        }
    }

    cout << endl;
}

//_______________________________________________________________________________________________