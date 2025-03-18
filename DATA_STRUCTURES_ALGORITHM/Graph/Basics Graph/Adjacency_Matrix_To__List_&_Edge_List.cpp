#include <bits/stdc++.h>
using namespace std;
 
//______Adjacency_Matrix_to_Adjacency_List___________________________________________________________
 
#define ll long long int

void Adjacency_Matrix_to_List(vector<vector<ll>> list, ll n) {
    vector<ll> adj_list[n+5];
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(list[i][j] == 1) {
                adj_list[i].push_back(j);
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        cout << i << " --> ";
        for(auto it: adj_list[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
}

void Adjacency_Matrix_to_List_Weighted(vector<vector<ll>> list, ll n) {
    vector<pair<ll, ll>> adj_list[n+5];
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(list[i][j] != 0 && list[i][j] != -1) {
                adj_list[i].push_back({j, list[i][j]});
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(auto it: adj_list[i]) {
            cout << i << " " << it.first << " " << it.second << endl;
        }
    }
}

//______Adjacency_Matrix_to_Edge_List____________________________________________________________


void Adjacency_Matrix_to_Edge_List(vector<vector<ll>> &list, ll n) {
    vector<pair<ll, ll>> edge_list;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(list[i][j] == 1) {
                edge_list.push_back({i, j});
            }
        }
    }
    
    for(int i=0; i<edge_list.size(); i++) {
        cout << edge_list[i].first << " " << edge_list[i].second << endl;
    }
}

class Edge{
    public:
      ll u, v, w;
      
    Edge(ll u, ll v, ll w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }  
};

void Adjacency_Matrix_to_Edge_List_Weighted(vector<vector<ll>> &list, ll n) {
    vector<Edge> edge_list;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(list[i][j] > 0) {
                edge_list.push_back({i, j, list[i][j]});
            }
        }
    }
    
    for(int i=0; i<edge_list.size(); i++) {
        cout << edge_list[i].u << " " << edge_list[i].v << " " << edge_list[i].w << endl;
    }
}


//_______________________________________________________________________________________________

 
int main(){
    ll n; cin >> n;
    // vector<vector<ll>> mat(n+5); //  Now create a vector of vector with size equal to row. Like arr[n][]
    
    // for(int i=0; i<n; i++) {
        // mat[i] = vector<ll>(n+5); // i-th row to the size of the column n; like arr[][n]
        // for(int j=0; j<n; j++) {
            // cin >> mat[i][j];
        // }
    // }
    
    
    // Adjacency_Matrix_to_List(mat, n);
    
    vector<vector<ll>> mat(n+5); //  Now create a vector of vector with size equal to row. Like arr[n][]
    
    for(int i=0; i<n; i++) {
    
        mat[i] = vector<ll>(n+5); // i-th row to the size of the column n; like arr[][n]
        
        for(int j=0; j<n; j++) {
            cin >> mat[i][j];
        }
    }
    
    Adjacency_Matrix_to_Edge_List_Weighted(mat, n);
    return 0; 
} 
 

//_______________________________________________________________________________________________