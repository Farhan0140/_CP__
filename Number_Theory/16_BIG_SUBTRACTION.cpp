#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

/* BIG_SUBTRACTION */ string Big_Sub(string s1, string s2);

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){
        string x, y, ans;
        cin >> x >> y;
        ans = Big_Sub(x, y);
        cout << ans << endl;
    }
}

//?----------------------------------------------------------------------------------------------


//*____________________________________BIG_SUBTRACTION___________________________________________

string Big_Sub(string s1, string s2){
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int len1 = s1.length();
    int len2 = s2.length();

    if(len1 > len2){
        int gap = abs(len2 - len1);
        while(gap--){
            s2.push_back('0');
        }
    }else{
        int gap = abs(len1 - len2);
        while(gap--){
            s1.push_back('0');
        }
    }

    int carry = 0;
    string sub = "";

    for(int i=0; i<s1.length(); i++){
        int x = s1[i] - '0' - carry;
        int y = s2[i] - '0';
        if(x < y){
            x += 10;
            carry = 1;
        }else{
            carry = 0;
        }
        int z = x - y;
        sub.push_back(z+'0');
    }

    while(sub.length()>1 && sub.back()=='0'){
        sub.pop_back();
    }

    reverse(sub.begin(), sub.end());
    return sub;
}

//*_______________________________________________________________________________________________