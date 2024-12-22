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
ll row, col; 

bool valid(ll c_i, ll c_j);
void DFS(ll src_i, ll src_j);

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    
    cin >> row >> col;
    ll src_i, src_j, dis_i, dis_j;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> Grid[i][j];

            if(Grid[i][j] == 'S') { src_i = i; src_j = j; }
            if(Grid[i][j] == 'D') { dis_i = i; dis_j = j; }
        }
    }

    memset(visited, false, sizeof(visited));

    DFS(src_i, src_j);
    return 0;
}
 
 
//_______________________________________________________________________________________________

bool valid(ll c_i, ll c_j) {
    return (c_i >= 0 && c_j >= 0 && c_i < row && c_j < col);
}

void DFS(ll src_i, ll src_j){
    visited[src_i][src_j] = true;
    cout << src_i << " " << src_j << endl;


    for(pair<ll, ll> child : Move) {
        ll c_i = src_i + child.first;
        ll c_j = src_j + child.second;

        if(valid(c_i, c_j) && !visited[c_i][c_j] && Grid[c_i][c_j] != '#') {
            DFS(c_i, c_j);
        }
    }
}

//_______________________________________________________________________________________________