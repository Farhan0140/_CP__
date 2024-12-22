#include <bits/stdc++.h>
using namespace std;

//_______________________________________________________________________________________________

// Time Complexity ---> O(2^n * n)


void All_Combinations(int n) {
    for(int mask=0; mask<(1 << n); mask++) {
        cout << mask << " --> ";
        for(int k=n-1; k>=0; k--) {
            if((mask >> k) & 1) {
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        }
         cout << endl;
    }
}


void All_Combinations(int arr[], int n) {
    for(int mask=0; mask<(1 << n); mask++) {
        cout << " { ";
        for(int k=0; k<n; k++) {
            int x = k;
            if((mask >> k) & 1) {
                cout << arr[x] << ",";
            } else {
                cout << "(" << arr[x] << ") ";
            }
        }
         cout << " }" << endl;
    }
}
//_______________________________________________________________________________________________


int main(){
    int n; cin >> n;
    All_Combinations(n);
    // int arr[n];
    // for(int i=0; i<n; i++) { cin >> arr[i]; }
    
    // All_Combinations(arr, n);    
    return 0;
}


//_______________________________________________________________________________________________