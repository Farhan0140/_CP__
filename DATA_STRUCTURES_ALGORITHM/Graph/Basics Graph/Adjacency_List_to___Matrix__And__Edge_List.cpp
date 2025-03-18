#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________
 
#define ll long long int

//_________Adjacency_List_To_Matrix______________________________________________________________

void Adjacency_List_To_Matrix(vector<ll> list[], ll n) {
    ll adj_mat[n+5][n+5];
    memset(adj_mat, 0, sizeof(adj_mat));
    
    for(int i=0; i<n; i++) {
        for(auto nodes: list[i]) {
            adj_mat[i][nodes] = 1;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
}

void Adjacency_List_To_Matrix_Weighted(vector<pair<int, int>> list[], ll n) {
    ll adj_mat[n+5][n+5];
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) {
                adj_mat[i][j] = 0;
            } else {
                adj_mat[i][j] = -1;
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(pair<int, int> it: list[i]) {
            ll node_val = it.first;
            ll node_weight = it.second;
            
            adj_mat[i][node_val] = node_weight;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
}

//_________Adjacency_List_To_Edge_List___________________________________________________________

void Adjacency_List_To_Edge_List(vector<ll> list[], ll n) {
    vector<pair<ll, ll>> edge_list;
    
    for(int i=0; i<n; i++) {
        for(ll it: list[i]) {
            edge_list.push_back({i, it});
        }
    }
    
    for(int i=0; i<edge_list.size(); i++) {
        cout << edge_list[i].first << " " << edge_list[i].second << endl;
    }
}


// For Weighted Graph

class Edge {
    public:
      ll u, v, w;
      
    Edge(ll u, ll v, ll w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

void Adjacency_List_To_Edge_List_Weighted(vector<pair<ll, ll>>list[], ll n) {
    vector<Edge> edge_list;
    
    for(int i=0; i<n; i++) {
        for(pair<ll, ll> it: list[i]) {
            edge_list.push_back(Edge(i, it.first, it.second));
        }
    }
    
    for(int i=0; i<edge_list.size(); i++) {
        cout << edge_list[i].u << " " << edge_list[i].v << " " << edge_list[i].w << endl;
    }
}


//_______________________________________________________________________________________________

 
int main(){
    // For Unweighted graph
    // int n, e; cin >> n >> e;
    // vector<ll> list[n+5];
    // while(e--) {
        // int u, v; cin >> u >> v;
        // list[u].push_back(v);
        // list[v].push_back(u); // For Undirected Graph;
    // }
    
    // Adjacency_List_To_Matrix(list, n);
    
    // For Weighted graph
    // int n, e; cin >> n >> e;
    // vector<pair<int, int>> list[n+5];
    
    // while(e--) {
        // int u, v, w; cin >> u >> v >> w;
        // list[u].push_back({v, w});
        // list[v].push_back({u, w}); // For Undirected Graph
    // }
    
    // Adjacency_List_To_Matrix_Weighted(list, n);
    
    int n, e; cin >> n >> e;
    vector<pair<ll, ll>> list[n+5];
    while(e--) {
        int u, v, w; cin >> u >> v >> w;
        list[u].push_back({v, w});
        list[v].push_back({u, w}); // For Undirected Graph;
    }
    
    Adjacency_List_To_Edge_List_Weighted(list, n);
    return 0;
}
 
 
//_______________________________________________________________________________________________

//4 4
//0 1 5
//0 2 2
//1 3 1
//2 3 9