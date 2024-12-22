#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________

#define ll long long int
#define all(x) x.begin(),x.end()
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

const ll S = 1e5+5;
vector<int> Arr[S];
bool visited[S];
ll Parent[S];
bool is_cycle = false;

void DFS(ll src);
 
//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    int n, e; cin >> n >> e;
    while(e--) {
        int u, v; cin >> u >> v;
        Arr[u].push_back(v);
        Arr[v].push_back(u); // for Undirected Graph
    }

    memset(visited, false, sizeof(visited));
    memset(Parent, -1, sizeof(Parent));

    int src; cin >> src;
    DFS(src);

    if(is_cycle) {
        cout << "Cycle Detected" << endl;
    } else {
        cout << "Cycle Not Detected" << endl;  
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________

void DFS(ll src) {
    visited[src] = true;

    for(ll child: Arr[src]) {
        if(visited[child] && child != Parent[src]) {
            is_cycle = true;
        }
        if(!visited[child]) {
            DFS(child);
        }
    }
}

//_______________________________________________________________________________________________