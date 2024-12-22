#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(2^n) --> After Memoization O(n)
 
//_______________________________________________________________________________________________

// https://quanticdev.com/tools/recursion-visualization/

//_______________________________________________________________________________________________

#define ll long long int
#define all(x) x.begin(),x.end()
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

const ll S = 1e5+5;
ll DP[S];
 
//_______________________________________________________________________________________________

ll Fibonacci(ll n) {
    if(n == 0 || n == 1) { return n; }

    if(DP[n] != -1) {
        return DP[n];
    }

    return DP[n] = Fibonacci(n-1) + Fibonacci(n-2);
}

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    memset(DP, -1, sizeof(DP));
    ll n; cin >> n;
    cout << Fibonacci(n) << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________