#include <bits/stdc++.h>
using namespace std;

//   Time Complexity: O(N * logN)
//_______________________________________________________________________________________________

#define ll long long int
#define all(x) x.begin(),x.end()

//_______________________________________________________________________________________________

class Items{
    public:
      ll weight, value;
    
    Items(ll w, ll v) {
        this->weight = w;
        this->value = v;
    }
};

bool Cmp(Items a, Items b) {
    double ratio_1 = (double)a.value / (double)a.weight;
    double ratio_2 = (double)b.value / (double)b.weight;
    return ratio_1 > ratio_2;
}

//_______________________________________________________________________________________________
 
 
int main(){
    // cout << "Enter the Size of Array: ";
    ll n; cin >> n;
    // cout << "Enter Weight & Value {weight, value}\n";

    vector<Items> item; 

    for(int i=0; i<n; i++) {
        ll w, v; cin >> w >> v;
        item.push_back(Items(w, v));
    }

    ll knapsack; cin >> knapsack; // the bag size
    sort(all(item), Cmp);

    double total_profit = 0;

    for(Items it: item) {
        if(it.weight <= knapsack) {
            knapsack -= it.weight;
            total_profit += it.value;
        } else {
            total_profit += it.value * ((double)knapsack / (double)it.weight);
            break;
        }
    }

    cout << total_profit << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________

/*

3
10 60
20 100
30 120
50

--> 240

*/