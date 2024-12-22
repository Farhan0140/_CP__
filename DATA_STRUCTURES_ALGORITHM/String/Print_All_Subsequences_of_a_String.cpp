#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________

#define ll long long int
#define IOS (ios_base :: sync_with_stdio(false), cin.tie(NULL));

ll Subsequences(string s, string output[]);

//_______________________________________________________________________________________________
 
 
int main(){
    IOS;
    string arr[10005];
    string s; cin >> s;

    ll output_arr_size = Subsequences(s, arr);

    for(int i=0; i<output_arr_size; i++) {
        cout << arr[i] << "\n";
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________

ll Subsequences(string s, string output[]) {
    if(s.length() == 0) {
        output[0] = "";
        return 1;
    }

    ll Smaller_Output_Size = Subsequences(s.substr(1), output);

    for(int i=0; i<Smaller_Output_Size; i++) {
        output[i + Smaller_Output_Size] = s[0] + output[i];
    }

    return 2 * Smaller_Output_Size;
}

//_______________________________________________________________________________________________