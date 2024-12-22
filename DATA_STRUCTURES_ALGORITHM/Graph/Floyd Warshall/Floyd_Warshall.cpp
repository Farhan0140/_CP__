#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________

#define ll long long int
#define all(x) x.begin(),x.end()
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

const ll INF = 1e18;

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    ll n, e; cin >> n >> e;
    ll Adj[n+5][n+5];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) {
                Adj[i][j] = 0;
            } else {
                Adj[i][j] = INF;
            }
        }
    }

    while(e--) {
        ll u, v, w; cin >> u >> v >> w;
        Adj[u][v] = w;
    }

    bool is_cycle = false;

    for(int k=0; k<n; k++) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(Adj[i][k] + Adj[k][j] < Adj[i][j]) {
                    Adj[i][j] = Adj[i][k] + Adj[k][j];
                }
            }

            if(Adj[i][i] < 0) {
                is_cycle = true;
                break;
            }
        }
    }

    if(is_cycle) {
        cout << "Cycle Detected" << endl;
    } else {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(Adj[i][j] == INF) {
                    cout << "INF" << " ";
                } else {
                    cout << Adj[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________