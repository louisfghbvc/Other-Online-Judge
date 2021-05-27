#include <bits/stdc++.h>

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

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

LL dp[N][105]; // ways before i, cur j
int arr[N];
int n, m;

LL dfs(int i, int pre = 0){
    if(i >= n) return pre <= m;
    if(dp[i][pre] != -1) return dp[i][pre];
    LL res = 0;
    if(arr[i]){
        if(pre == 0 || abs(arr[i] - pre) <= 1){
            res += dfs(i+1, arr[i]);
        }
    }
    else{
        if(i != 0){
            for(int nxt: {pre-1, pre, pre+1}){
                if(nxt <= 0 || nxt > m) continue;
                res += dfs(i+1, nxt);
                res %= mod;
            }
        }
        else{
            for(int j = 1; j <= m; ++j){
                res += dfs(i+1, j);
                res %= mod;
            }
        }
    }
    return dp[i][pre] = res;
}

void solve(int T){
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    cout << dfs(0) << "\n";

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
