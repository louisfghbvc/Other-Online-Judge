#include <bits/stdc++.h>
 
// #pragma GCC optimize("O3")
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/
 
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }
 
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
(1 + 2 + 4)

S = (1 - p^(x+1)) / (1 - p)

**/

LL fpow(LL a, LL b, LL m = mod){
    LL res = 1;
    while(b){
        if(b & 1) res = res*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return res;
}

LL modinv(LL x, LL m = mod){
    return fpow(x, m-2);
}

LL sum(LL n){
    LL x = n+1, y = n;
    if(x & 1) y >>= 1;
    else x >>= 1;
    return x * y % (mod-1);
}

void solve(int T){
    LL n;
    cin >> n;
    vector<ii> arr(n);
    for(auto &it: arr)
        cin >> it.first >> it.second;
        
    vi suf(n+1);
    suf[n] = 1;
    for(int i = n-1; i >= 0; --i){
        suf[i] = suf[i+1] * (arr[i].second+1) % (mod-1);
    }
    
    LL nd = 1; // nums of divisors
    LL sumd = 1; // sum of divisors
    LL prod = 1; // product of divisors
    LL prev_pow = 1; // rolling prefix

    for(int i = 0; i < n; ++i){
        nd *= arr[i].second+1;
        nd %= mod;
        sumd = sumd * (1 - fpow(arr[i].first, arr[i].second+1)) % mod * modinv(1 - arr[i].first) % mod;
        LL tmp_pow = sum(arr[i].second) * prev_pow % (mod-1) * suf[i+1] % (mod-1);
        prod = prod * fpow(arr[i].first, tmp_pow) % mod;

        prev_pow *= arr[i].second+1;
        prev_pow %= mod-1;
    }

    cout << nd << " " << sumd << " " << prod << "\n";
}   
 
int main()
{
    // Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
 
/**
Enjoy the problem.
**/
