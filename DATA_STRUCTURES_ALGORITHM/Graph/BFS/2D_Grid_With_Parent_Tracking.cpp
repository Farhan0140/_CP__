#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________
/*
5 6
S.....
......
######
......
D.....
*/
//_______________________________________________________________________________________________
 
#define ll long long int
#define all(x) x.begin(),x.end()

#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));
 
//_______________________________________________________________________________________________

const ll S = 1e2+5;
//                              Left     Right   Up       Down
vector<pair<int, int>> Move = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
char Grid[S][S];
bool visited[S][S];
map<pair<ll, ll>, pair<ll, ll>> Parent; // pair<ll, ll> Parent[S][S]
ll n, m; 

bool valid(ll c_i, ll c_j);
void BFS(ll src_i, ll src_j);

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    
    cin >> n >> m;
    ll src_i, src_j, dis_i, dis_j;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> Grid[i][j];

            if(Grid[i][j] == 'S') { src_i = i; src_j = j; }
            if(Grid[i][j] == 'D') { dis_i = i; dis_j = j; }
        }
    }

    memset(visited, false, sizeof(visited));

    BFS(src_i, src_j);

    if(visited[src_i][src_j]) {
        pair<ll, ll> p = {dis_i, dis_j};
        vector<pair<ll, ll>> Paths;

        while(true) {
            ll new_di = Parent[{dis_i, dis_j}].first;
            ll new_dj = Parent[{dis_i, dis_j}].second;
            dis_i = new_di; dis_j = new_dj;

            if(Grid[dis_i][dis_j] == 'S') { break; }
            Grid[dis_i][dis_j] = 'X';
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << Grid[i][j];
        }
        cout << endl;
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________

bool valid(ll c_i, ll c_j) {
    return (c_i >= 0 && c_j >= 0 && c_i < n && c_j < m);
}

void BFS(ll src_i, ll src_j){
    queue<pair<ll, ll>> q;

    q.push({src_i, src_j});
    visited[src_i][src_j] = true;

    while(!q.empty()) {
        pair<ll, ll> parent = q.front(); q.pop();
        ll par_i = parent.first;
        ll par_j = parent.second;

        for(pair<ll, ll> child : Move) {
            ll c_i = par_i + child.first;
            ll c_j = par_j + child.second;

            if(valid(c_i, c_j) && !visited[c_i][c_j] && Grid[c_i][c_j] != '#') {
                q.push({c_i, c_j});
                visited[c_i][c_j] = true;
                Parent[{c_i, c_j}] = {par_i, par_j}; // Parent[c_i][c_j] = {par_i, par_j};
            }
        }
    }
}

//_______________________________________________________________________________________________