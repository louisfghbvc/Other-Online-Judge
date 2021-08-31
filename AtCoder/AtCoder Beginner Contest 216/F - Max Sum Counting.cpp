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
 
const int N = 5e3+5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
/**
 * sort by A, increasing.
 * tricky part is that, to propagate next numbers of ways doesn't consider A[i] is enough
 * since in last A[i] can cover B[i]
**/

LL dp[N][N];

void solve(int T){
    int n;
    cin >> n;
    vector<ii> arr(n+1);
    for(int i = 1; i <= n; ++i)  cin >> arr[i].first;
    for(int i = 1; i <= n; ++i)  cin >> arr[i].second;
    sort(arr.begin() + 1, arr.begin() + 1 + n);

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    LL res = 0;

    // enumerate maximum until A[i].
    for(int i = 1; i <= n; ++i){
        LL cnt = 0;
        // enumerate sum, consider add this B[i]
        for(int j = 0; j <= arr.back().first; ++j) if(arr[i].first >= j + arr[i].second){
            cnt += dp[i-1][j];
        }
        cnt %= mod;
        res += cnt;
        res %= mod;
        // subset until B[0:i]
        for(int j = 0; j <= arr.back().first; ++j){
            // not choose B[i]
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
            // choose B[i], only smaller than maximum value can add
            // no matter A[i] is smaller or big, just add B[i], since finally can get.
            if(j + arr[i].second <= arr.back().first){
                dp[i][j + arr[i].second] += dp[i-1][j];
                dp[i][j + arr[i].second] %= mod;
            }
        }
    }

    cout << res << "\n";

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
