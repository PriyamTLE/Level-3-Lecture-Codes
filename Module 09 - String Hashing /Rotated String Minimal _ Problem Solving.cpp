#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#ifdef Priyansh31dec
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef __int128 ell;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int mod_add(ll a, ll b, int m) {return (a + b) % m;}
int mod_mul(ll a, ll b, int m) {return (a * b) % m;}
int mod_sub(ll a, ll b, int m) {return (((a - b) % m) + m) % m;}
int mod_div(ll a, ll b, int m) {return mod_mul(a, mminvprime(b, m), m);}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
/*--------------------------------------------------------------------------------------------------------------------------*/
struct Hashing{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009};
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;
    Hashing(string a){
        primes = sz(hashPrimes);
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length(); 
        for(int i = 0; i < sz(hashPrimes); i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mminvprime(powersOfBase[i][n], hashPrimes[i]);
            for(int j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = (inversePowersOfBase[i][j + 1] * base) % hashPrimes[i];
            } 
        }
        for(int i = 0; i < sz(hashPrimes); i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++){
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    int substringHash(int l, int r){
        ll hash;
        ll val1 = hashValues[0][r];
        ll val2 = l > 0 ? hashValues[0][l - 1] : 0LL;
        hash = ((val1 - val2 + hashPrimes[0]) * inversePowersOfBase[0][l]) % hashPrimes[0];
        return hash;
    }
    
    int combinedSubstringHash(int l1, int r1, int r2){
        ll hash1 = substringHash(l1, r1);
        hash1 = (hash1 + hashValues[0][r2] * powersOfBase[0][r1 - l1 + 1]) % hashPrimes[0]; 
        return hash1;
    }
};
 
int rotatedHash(Hashing& hs, int rotation, int r){
    int leftIndex = rotation;
    int rightIndex = r + rotation;
    if(rightIndex < hs.n)
        return hs.substringHash(leftIndex, rightIndex);
    else
        return hs.combinedSubstringHash(leftIndex, hs.n - 1, rightIndex - hs.n);
    
}
 
bool isSmaller(int ind1, int ind2, Hashing& hs, string &s){ //logn
    int n = s.length();
    int start = 0, end = n - 2;
    int diffIndex = n - 1;
 
    if(rotatedHash(hs, ind1, n - 1) == rotatedHash(hs, ind2, n - 1))
        return false;
 
    while(start <= end){
        int mid = (start + end) / 2;
        if(rotatedHash(hs, ind1, mid) == rotatedHash(hs, ind2, mid)){
            start = mid + 1;
        }else{
            diffIndex = mid;
            end = mid - 1;
        }
    }
    
    return s[(diffIndex + ind1) % n] < s[(diffIndex + ind2) % n];
}
 
string rotatedString(string &s, int rotation){
    string prefix = s.substr(0, rotation);
    string suffix = s.substr(rotation, s.length() - rotation);
    return suffix + prefix;
}
void solve() {
    string s;
    cin >> s;
    Hashing hs = Hashing(s);
    
    char smallest = *min_element(all(s));
    int n = s.length();
    int bestSoFar = 0;
    for(int i = 1; i < n; i++){
        if(s[i] != smallest){
            continue;
        }
        if(isSmaller(i, bestSoFar, hs, s)){
            bestSoFar = i;
        }
    }
    
    cout << rotatedString(s, bestSoFar) << nline;
 
}
 
int main() {
    #ifdef Priyansh31dec
        freopen("Error.txt", "w", stderr);
    #endif
        fastio();
        auto start1 = high_resolution_clock::now();
        solve();
        auto stop1 = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifdef Priyansh31dec
        cerr << "Time: " << duration . count() / 1000 << endl;
    #endif

}