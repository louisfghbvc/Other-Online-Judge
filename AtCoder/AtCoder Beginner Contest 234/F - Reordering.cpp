/**                                          
 __         ______     __  __     __     ______     ______   ______     __  __     ______     __   __   ______    
/\ \       /\  __ \   /\ \/\ \   /\ \   /\  ___\   /\  ___\ /\  ___\   /\ \_\ \   /\  == \   /\ \ / /  /\  ___\   
\ \ \____  \ \ \/\ \  \ \ \_\ \  \ \ \  \ \___  \  \ \  __\ \ \ \__ \  \ \  __ \  \ \  __<   \ \ \'/   \ \ \____  
 \ \_____\  \ \_____\  \ \_____\  \ \_\  \/\_____\  \ \_\    \ \_____\  \ \_\ \_\  \ \_____\  \ \__|    \ \_____\ 
  \/_____/   \/_____/   \/_____/   \/_/   \/_____/   \/_/     \/_____/   \/_/\/_/   \/_____/   \/_/      \/_____/                                       
**/
#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(All(x)); x.erase(unique(All(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/
 
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }
 
const int N = 5e3+5;
const LL INF = 1e13;
const int mod = 998244353;
const LL MXP = 1e10;
/**
**/

LL fpow(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}
LL mod_inv(LL x){
    return fpow(x, mod-2);
}

LL fac[N], ifac[N];

void init(){
    fac[0] = 1;
    for(int i = 1; i < N; ++i)
        fac[i] = fac[i-1] * i % mod;
    ifac[N-1] = mod_inv(fac[N-1]);
    for(int i = N-2; i >= 0; --i)
        ifac[i] = (ifac[i+1] * (i+1)) % mod;
}

LL choose(int n, int r){
    return fac[n] * ifac[r] % mod * ifac[n-r] % mod;
}

LL dp[27][N];

void solve(int _){
    string s;
    cin >> s;

    int fre[26] = {};
    for(char c: s) fre[c-'a']++;
    int n = s.size();

    dp[0][0] = 1;
    for(int i = 0; i < 26; ++i){
        for(int j = 0; j <= n; ++j){
            for(int k = 0; k <= min(j, fre[i]); ++k){
                dp[i+1][j] += dp[i][j-k] * choose(j, k);
                dp[i+1][j] %= mod;
            }
        }
    }

    LL res = 0;
    for(int i = 1; i <= n; ++i)
        res = (res + dp[26][i]) % mod;
    cout << res << "\n";
}

int main()
{
    init();
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
