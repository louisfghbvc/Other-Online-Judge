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
 
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

map<LL, int> dp;
int dfs(LL x){
    if(!x) return 0;
    if(dp.count(x)) return dp[x];
    LL a = x/10, b = x%10;
    if(dfs(a) <= 1 && b >= 1 && b <= 3) return dp[x] = 1;
    if(dfs(a) <= 2 && b >= 2 && b <= 6) return dp[x] = 2;
    if(dfs(a) <= 3 && b >= 3 && b <= 9) return dp[x] = 3;
    if(dfs(a) <= 4 && b >= 4 && b <= 9) return dp[x] = 4; // 14~19
    if(dfs(a-1) <= 4 && b >= 0 && b <= 2) return dp[x] = 4; // 10, 11, 12
    return dp[x] = 5;
}

void solve(int T){
    LL n;
    cin >> n;
    cout << dfs(n) << "\n";
}   
 
int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    louisfghbvc
        solve(1);
    return 0;
}
 
/**
Enjoy the problem.
**/
