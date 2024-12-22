#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!-----------------------------------------------------------------------------------------------

/* BIG_SUMMATION */ string Big_Sum(string s1, string s2);

//?-----------------------------------------------------------------------------------------------

int main(){
    fast_read();

    while(true){
        string x, y, ans;
        cin >> x >> y;
        ans = Big_Sum(x, y);
        cout << ans << endl;
    }
}

//?----------------------------------------------------------------------------------------------


//*_______________________________________BIG_SUMMATION___________________________________________

string Big_Sum(string s1, string s2){
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

    int carry=0;
    string sum = "";

    for(int i=0; i<s1.length(); i++){
        int x = (s1[i] - '0') + (s2[i] - '0') + carry;
        char lastDigit = (x%10)+'0';
        sum.push_back(lastDigit);
        carry = x/10;
    }
    if(carry > 0){
        sum.push_back(carry+'0');
    }
    reverse(sum.begin(), sum.end());
    return sum;
}

//*_______________________________________________________________________________________________