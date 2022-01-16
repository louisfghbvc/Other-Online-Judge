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
 
const int N = 1e4+5;
const LL INF = 1e13;
const int mod = 998244353;
const LL MXP = 1e10;
/**
**/

string s;
int mask=0;

pair<int, int> dp[N][1<<10][2][2];
LL pow10[N];

pair<int, int> dfs(int i, int cur, bool bound=true, bool leading_zero=true){
    if(i >= s.size()){
        if((cur & mask) == mask) return {1, 0};
        return {0, 0};
    }

    pair<int, int> &res = dp[i][cur][bound][leading_zero]; 
    if(res.first != -1) return res;

    res = {0, 0};
    // current can goto
    int cc = bound ? s[i] - '0' : 9;
    for(int b = 0; b <= cc; ++b){
        bool nbound = bound && b == (s[i] - '0');
        int ncur = leading_zero && b == 0 ? cur : cur | (1<<b);
        pair<int, int> cur_dp = dfs(i+1, ncur, nbound, leading_zero && b == 0);
        res.first = (res.first + cur_dp.first) % mod;
        res.second = (res.second + 1LL * b * pow10[s.size() - 1 - i] % mod * cur_dp.first % mod) % mod;
        res.second = (res.second + cur_dp.second) % mod;
    }

    return res;
}

void solve(int _){
    memset(dp, -1, sizeof dp);
    cin >> s;

    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        int x;
        cin >> x;
        mask |= 1<<x;
    }

    pow10[0] = 1;
    for(int i = 1; i < N; ++i)
        pow10[i] = pow10[i-1] * 10 % mod;

    cout << dfs(0, 0).second << "\n";
}

int main()
{
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
