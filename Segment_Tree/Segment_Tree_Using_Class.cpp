#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int SZ = 1e5 + 9; 


ll arr[SZ];

class Segment_Tree {
    private:
      vector<ll> Tree;

      void Build_Tree(ll Node, ll Begin, ll End) {
          
          if(Begin == End) {
                
              Tree[Node] = arr[Begin];
              return;

          }

          ll Mid = (Begin + End) >> 1;
          ll Left_Child = Node << 1;
          ll Right_Child = Left_Child | 1; // OR: Left_Child + 1;

          Build_Tree(Left_Child, Begin, Mid);
          Build_Tree(Right_Child, Mid + 1, End);

          Tree[Node] = Tree[Left_Child] + Tree[Right_Child];

      }

      void Update_Tree(ll Node, ll Begin, ll End, ll Index, ll Value) {
          
          if(Index < Begin || Index > End) {

              return;

          }

          if(Begin == End) {

              Tree[Node] = Value;
              return;

          }

          ll Mid = (Begin + End) >> 1;
          ll Left_Child = Node << 1;
          ll Right_Child = Left_Child | 1; // OR: Left_Child + 1;

          Update_Tree(Left_Child, Begin, Mid, Index, Value);
          Update_Tree(Right_Child, Mid + 1, End, Index, Value);

          Tree[Node] = Tree[Left_Child] + Tree[Right_Child];

      }

      ll Query_Tree(ll Node, ll Begin, ll End, ll i, ll j) {

          if(j < Begin || i > End) {
              
              return 0;

          }

          if(i <= Begin && j >= End) {
              
              return Tree[Node];

          }

          ll Mid = (Begin + End) >> 1;
          ll Left_Child = Node << 1;
          ll Right_Child = Left_Child | 1; // OR: Left_Child + 1;

          return Query_Tree(Left_Child, Begin, Mid, i, j) + Query_Tree(Right_Child, Mid + 1, End, i, j);

      }
    
    public:
      
      void Build(ll n) {

          Tree.resize(4 * SZ);
          Build_Tree(1, 1, n);

      }

      void Update(ll n, ll index, ll value) {

          Update_Tree(1, 1, n, index, value);

      }

      ll Query(ll n, ll l, ll r) {

          return Query_Tree(1, 1, n, l, r);

      }
};


//___________________________________________________________________________________________________________________________________________________


int main(){

    ll n, q; cin >> n >> q;
    for(int i=1; i<=n; i++) {

        cin >> arr[i];

    }


    Segment_Tree seg_tree;
    seg_tree.Build(n);

    while(q--) {

        ll chk; cin >> chk;
        if(chk == 1) {
            
            ll idx, val; cin >> idx >> val; 
            idx++;
            seg_tree.Update(n, idx, val);
            
        } else {
            
            ll l, r; cin >> l >> r; 
            l++;
            cout << seg_tree.Query(n, l, r) << endl;

        }
    }

    return 0;

}


//___________________________________________________________________________________________________________________________________________________