//-------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define Mod 1000000007
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//!------------------------------------------------------------------------

/* PRIMALITY_TEST */ bool P_T(ll n);
/* SIEVE_OF_ERATOSTHENES */ void S_O_E(ll n);
/* K-th Prime_Number */ void K_P();
/* PRIME_FACTORIZATION */ void P_F(ll n);
/* BINARY_EXPONENTIATION */ ll B_E(ll base, ll power);

// MATRIX_EXPONENTIATION {
        #define Size 200
        void Power_Matrix(ll A[][Size], ll n, ll p);
        void multiplication(ll A[][Size], ll B[][Size], ll n);
// }

// FIBONACCI_FINDING_using_MATRIX_EXPONENTIATION {
        #define fs 5
        void FibMul(ll A[][fs], ll B[][fs]);
        void FibSolve(ll a, ll b, ll power);
// }

/* COUNT_NUMBER_OF_DIVISOR */ void C_D(ll n);
/* EUCLID_ALGORITHM --> GCD */ ll GCD(ll a, ll b);

// SEGMENTED_SIEVE {
        void Sieve(int R);
        void Segmented_Sieve(int L, int R);
// }

/* MODULAR_ARITHMETIC */ void MOD(string s, ll m);
/* MODULAR_INVERSE */ void M_I(ll a, ll b, ll m);

// BINOMIAL_COEFFICIENT_USING_MODULO {
        ll Factorial(ll n);
        void nCr();
// }

/* EULER'S_TOTIENT_FUNCTION */ void E_T_F(ll n);

/* BIG_SUMMATION */ string Big_Sum(string s1, string s2);
/* BIG_SUBTRACTION */ string Big_Sub(string s1, string s2);
/* BIG_MOD */ ll Big_Mod(ll base, ll power, ll mod);

//!-----------------------------------------------------------------------

//?-----------------------------------------------------------------------

int main(){
    fast_read();
    while(true){
        ll a, b, m; cin >> a;
        E_T_F(a);
    }
}

//?-----------------------------------------------------------------------

//*_________________________PRIMALITY_TEST________________________________

bool P_T(ll n){
	if(n < 2) return false;       // 0 and 1 is not a prime number
    if(n <= 3) return true;         // 2 and 3 is prime number
    if(n%2 == 0) return false;        // We know, all even number is not prime number except 2, because all even number are divisible by 2
    for(int i=3; i<=sqrt(n); i+=2){      // Since, all even number are not prime number, except 2, so we need to check just all odd numbers
    	if(n%i == 0) return false;       
    }
    return true;
}

//*______________________SIEVE_OF_ERATOSTHENES____________________________

void S_O_E(ll n){
	ll prime[n+3];       // declaring an array
    memset(prime, 0, sizeof(prime));     // Push the value 0 of all index, Let the value of all index be 0, means all index are prime
    
    for(int i=2; i*i<=n; i++){      // i*i<=n.   >> i<sqrt(n)
    	if(prime[i] == 0){     // if prime[i] == 0 that means this index is prime; if prime[i] == 1; that's means this index is not prime
        	for(int j=i*i; j<=n; j+=i){  // when i=2; j=2*2=4; j+=2= 6, 8, 10
            	prime[j] = 1;     // prime[j] = 1; means j th index is true and this index is not prime
            }
        }
    }
    
    for(int i=2; i<=n; i++){
    	if(prime[i] != 1){     //If the value of index is not 1, then that index is prime
        	cout << i << " ";
        }
    }
}

//*____________________________K th_PRIME_NUMBER__________________________

int Prime[90000001];      //If we declare an array globally. It's auto initialize value 0 in all indexes, don't need to use memset
int KK = 90000000;
vector<int>primes;        // All prime numbers are stored in this vector

void K_P(){
    for(int i=2; i*i<=KK; i++){
    	if(Prime[i] == false){
        	for(int j=i*i; j<=KK; j+=i){
            	Prime[j] = true;
            }
        }
    }
    
    for(int i=2; i<=KK; i++){
    	if(Prime[i] == false){
        	primes.push_back(i);
        }
    }
}

//*_________________________PRIME_FACTORIZATION__________________________

void P_F(ll n){
	int cnt=0;
	for(int i=2; i*i<=n; i++){
    	if(n%i == 0){
        	while(n%i == 0){
            	cnt++;
                n = n/i;
            }
            cout << i << "^" << cnt << " , ";
            cnt=0;
        }
    }
    if(n > 1) cout << n << "^" << 1 << endl;
    else cout << endl;
}

//*___________________BINARY_EXPONENTIATION_____________________________

ll B_E(ll base, ll power){
    ll result = 1;
    while(power){
        if(power%2 != 0){
            result = (result*base) % Mod;
            power--;
        }else{
            base = (base*base) % Mod;
            power /= 2;
        }
    }
    return result % Mod;
}

//*____________________MATRIX_EXPONENTIATION___________________________

ll M_Matrix[Size][Size], Result[Size][Size];

void multiplication(ll A[][Size], ll B[][Size], ll n){
    ll res[n+1][n+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            res[i][j]=0;
            for(int k=1; k<=n; k++){
                ll x = (A[i][k] * B[k][j]);
                res[i][j] = (res[i][j]+x);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            A[i][j] = res[i][j];
        }
    }
}

void Power_Matrix(ll A[][Size], ll n, ll p){
    for(int i=1; i<=n; i++){                    //
        for(int j=1; j<=n; j++){                //
            if(i == j){                         //
                Result[i][j] = 1;               // This Nested loop Using for making Result Diagonally 1, and other index 0
            }else{                              // Because, if we multiply A matrix with this Result, This Matrix Value will not change ,,
                Result[i][j] = 0;               //
            }                                   //
        }                                       //
    }
    
    while(p){
        if(p%2 != 0){
            multiplication(Result, A, n);
            p--;
        }else{
            multiplication(A, A, n);
            p /= 2;
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            A[i][j] = Result[i][j];
        }
    }
}

//*_________FIBONACCI_FINDING_using_MATRIX_EXPONENTIATION_____________

ll FibBase[fs][fs], FibResult[fs][fs];

void FibMul(ll A[][fs], ll B[][fs]){
    ll res[3][3];
    for(ll i=0; i<2; i++){
        for(ll j=0; j<2; j++){
            res[i][j] = 0;
            for(ll k=0; k<2; k++){
                ll x = (A[i][k] * B[k][j]);
                res[i][j] = (res[i][j]+x);
            }
        }
    }
    
    for(ll i=0; i<2; i++){
        for(ll j=0; j<2; j++){
            A[i][j] = res[i][j];
        }
    }
}

void FibSolve(ll a, ll b, ll power){
    FibBase[0][0] = 0;
    FibBase[0][1] = FibBase[1][0] = FibBase[1][1] = 1;
    
    FibResult[0][1] = FibResult[1][0] = 0;
    FibResult[0][0] = FibResult[1][1] = 1;
    
    power--;
    
    while(power){
        if(power%2 == 1){
            FibMul(FibResult, FibBase);
            power--;
        }else{
            FibMul(FibBase, FibBase);
            power /= 2;
        }
    }
    
    ll ans = a * FibResult[0][1] + b * FibResult[1][1];
    cout << ans << endl;
}

//*____________PRINT_AND_COUNT_NUMBER_OF_DIVISOR_IN_N___________________

set<ll>div_set;

void C_D(ll n){
    for(int i=1; i<=sqrt(n); i++){
        if(n%i == 0){
            ll x = i;
            ll y = n/i;
            div_set.insert(x);
            div_set.insert(y);
        }
    }
}

//*____________________EUCLID_ALGORITHM --> GCD__________________________

ll GCD(ll a, ll b){
    if(b == 0){
        return a;
    }
    return GCD(b, (a%b));
}

//*__________________________SEGMENTED_SIEVE_____________________________

vector<int>v1;

void Sieve(int R){
    ll arr[R+5];
    memset(arr, 0, sizeof(arr));
    for(int i=2; i*i<=R; i++){
        if(arr[i] == 0){
            for(int j=i*i; j<=R; j+=i){
                arr[j] = 1;
            }
        }
    }

    for(int i=2; i<=R; i++){
        if(arr[i] == 0){
            v1.push_back(i);
        }
    }
}

void Segmented_Sieve(int L, int R){
    if(L == 1) L++;
    ll size = (R-L)+1;
    ll arr[size+1];
    memset(arr, 0, sizeof(arr));

    for(int p:v1){
        if(p*p <= R){
            ll g = (L/p)*p;
            if(g < L) g+=p;
            for(; g<=R; g+=p){
                if(g != p){
                    arr[g-L] = 1;
                }
            }
        }
    }

    for(int i=0; i<size; i++){
        if(arr[i] == 0){
            cout << i+L << endl;
        }
    }
    v1.clear();
}

//*________________________MODULAR_ARITHMETIC____________________________

void MOD(string s, ll m){
    ll ans = 0;
    for(int i=0; i<s.length(); i++){
        ans = ans * 10 + (s[i] - '0');
        ans = ans % 10;
    }
    if((ans%m) == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

//*____________________________MODULAR_INVERSE____________________________

void M_I(ll a, ll b, ll m){
    ll x = B_E(b, m-2);        //TODO BINARY_EXPONENTIATION er vitore o m pathate hobe & sob jaigai m dara MOD korte hobe
    x %= m;

    ll ans1 = (a * x) % m; 
    ll ans2 = ((a % m) * (x % m)) % m;

    cout << ans1 << endl;
    cout << ans2 << endl;
}

//*________________BINOMIAL_COEFFICIENT_USING_MODULO_____________________
// use long long int

ll Factorial(ll n){
    ll result = 1;
    for(ll i=2; i<=n; i++){
        result = (result * i) % Mod;
    }
    return result % Mod;
}

void nCr(){
    ll n, r; cin >> n >> r;
    ll n1 = Factorial(n); 
    ll r1 = Factorial(r);
    ll k = Factorial(n-r);

    ll ans=n1, ans1, ans2;
    ans1 = B_E(r1, Mod-2);    // BINARY_EXPONENTIATION
    ans2 = B_E(k, Mod-2);    // BINARY_EXPONENTIATION

    ans = (ans*ans1) % Mod;
    ans = (ans*ans2) % Mod;

    ans = ans % Mod;

    cout << ans << endl;
}

//*__________________EULER'S_TOTIENT_FUNCTION____________________________

void E_T_F(ll n){      // using PRIME_FACTORIZATION
    ll ans = n;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            while(n%i == 0){
                n /= i;
            }
            ans *= (i-1);
            ans /= i;
        }
    }
    if(n > 1){
        ans *= (n-1);
        ans /= n;
    }
    cout << ans << endl;
}

//*________________________BIG_SUMMATION_________________________________

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

//*______________________BIG_SUBTRACTION_________________________________

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

//*___________________________BIG_MOD____________________________________

ll Big_Mod(ll base, ll power, ll mod){
    if(power == 0){
        return 1;
    }
    if(power%2 != 0){
        ll a = base%mod;
        ll b = (Big_Mod(base, power-1, mod));
        return (a*b)%mod;
    }
    else if(power%2 == 0){
        ll a = (Big_Mod(base, power/2, mod));
        return (a*a)%mod;
    }
    return -404;
}

//*----------------------------------------------------------------------

//TODO -- Use --> Better Comment. Vs Code Extension <--