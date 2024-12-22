#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(2^n)
 
//_______________________________________________________________________________________________

// https://quanticdev.com/tools/recursion-visualization/

//_______________________________________________________________________________________________

#define ll long long int
#define all(x) x.begin(),x.end()
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));
 
//_______________________________________________________________________________________________

ll Fibonacci(ll n) {
    if(n == 0 || n == 1) { return n; }
    return Fibonacci(n-1) + Fibonacci(n-2);
}

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    ll n; cin >> n;
    cout << Fibonacci(n) << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________