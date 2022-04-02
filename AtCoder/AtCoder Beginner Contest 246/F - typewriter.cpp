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
 
const int N = 1500+5;
const LL INF = 1e13;
const int mod = 998244353;
const LL MXP = 1e10;
/**
**/

LL fpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}

void solve(int T) {
    int n, l;
    cin >> n >> l;

    // goal: compute the number of distinct string that length is L
    // idea: use inclusion-exclusion principle, say choose row1 + row2 - (row1 & row2)
    
    vector<int> distinct(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c: s)
            distinct[i] |= 1<<(c-'a');
    }

    LL ans = 0;
    for (int m = 1; m < 1<<n; ++m) {
        int numberC = (1<<26)-1;
        for (int i = 0; i < n; ++i) {
            if (m >> i & 1)
                numberC &= distinct[i];
        }

        int bitC = __builtin_popcount(numberC);
        if (__builtin_popcount(m) % 2)
            ans = (ans + fpow(bitC, l)) % mod;
        else
            ans = ((ans - fpow(bitC, l)) % mod + mod) % mod;
    }

    cout << ans << "\n";
}   

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
