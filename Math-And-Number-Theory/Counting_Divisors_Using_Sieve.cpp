#include <bits/stdc++.h>
using namespace std;

#define ll long long int
//_______________________________________________________________________________________________

// TC O(n loglog n)

//_______________________________________________________________________________________________


int main(){
    ll n; cin >> n;

    //!----Divisor_list(1 to n)--------------------------------->
    vector<ll> divisor_list[n+1];

    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j+=i) {
            divisor_list[j].push_back(i);
        }
    }

    for(int i=1; i<=n; i++) {
        cout << i << " --> ";
        for(int j=0; j<divisor_list[i].size(); j++) {
            cout << divisor_list[i][j] << " ";
        }
        cout << endl;
    }



    //!---Count_Divisor(1 to n)------------------------------->

    vector<int>divisors(n+1, 0);
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j+=i) {
            divisors[j]++;
        }
    }

    cout << divisors[5] << endl;
    cout << divisors[8] << endl;
    cout << divisors[10] << endl;
    // or--->
    cout << divisor_list[5].size() << endl;
    cout << divisor_list[10].size() << endl;

    //-------------------------------------------------------->
    return 0;
}


//_______________________________________________________________________________________________