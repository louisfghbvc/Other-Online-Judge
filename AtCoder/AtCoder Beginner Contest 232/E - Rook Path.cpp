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
 
const int N = 1e6+5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
/**
**/

LL dp[N][2][2];
LL h, w, k;

LL dfs(bool same_x, bool same_y, int i=0){
    if(i == k) return same_x && same_y;
    LL &res = dp[i][same_x][same_y];
    if(res != -1) return res;
    
    res = 0;
    // move col
    if(same_x){
        res += (h-1) * dfs(0, same_y, i+1) % mod;
        res %= mod;
    }
    else{
        res += dfs(1, same_y, i+1) % mod;
        res %= mod;
        res += (h-2) * dfs(0, same_y, i+1) % mod;
        res %= mod;
    }
    if(same_y){
        res += (w-1) * dfs(same_x, 0, i+1) % mod;
        res %= mod;
    }
    else{
        res += dfs(same_x, 1, i+1) % mod;
        res %= mod;
        res += (w-2) * dfs(same_x, 0, i+1) % mod;
        res %= mod;
    }
    return res;
}

void solve(int T){
    memset(dp, -1, sizeof dp);
    cin >> h >> w >> k;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << dfs(x1==x2, y1==y2) << "\n";
}
 
int main()
{
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
