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
 
const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully

**/
LL dp[1024][N];

int n, m;
void genMask(int cur, int nxt, int i, vi &tot){
    if(i >= n){
        tot.push_back(nxt);
        return;
    }
    if(cur >> i & 1)
        genMask(cur, nxt, i + 1, tot);
    if(i != n-1 && !(cur >> i & 1) && !(cur & (1<<(i+1))))
        genMask(cur, nxt, i + 2, tot);
    if(!(cur >> i & 1))
        genMask(cur, nxt ^ (1<<i), i + 1, tot);
}

LL dfs(int mask, int j){
    if(j >= m) return mask == 0;
    if(dp[mask][j] != -1) return dp[mask][j];
    LL res = 0;
    vi nxt;
    genMask(mask, 0, 0, nxt);
    for(LL nxt_mask: nxt){
        res += dfs(nxt_mask, j+1);
        res %= mod;
    }
    return dp[mask][j] = res;
}

void solve(int T){
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    cout << dfs(0, 0) << "\n";
}   
 
int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
 
/**
Enjoy the problem.
**/


// USACO bottom up. tricky.
LL dp[1024][2];

void solve(int T){
    int n, m;
    cin >> n >> m;
    dp[0][0] = 1;
    for (int j = 0; j < m; j++) for (int i = 0; i < n; i++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        dp[mask][1] = dp[mask ^ (1 << i)][0]; // Vertical/no tile
        if (i && !(mask & (1 << i)) && !(mask & (1 << i - 1))) // Horizontal tile
          dp[mask][1] += dp[mask ^ (1 << i - 1)][0];

        if (dp[mask][1] >= mod) dp[mask][1] -= mod;
      }
      for (int mask = 0; mask < (1 << n); mask++) dp[mask][0] = dp[mask][1];
    }
	cout << dp[0][0];
}  
