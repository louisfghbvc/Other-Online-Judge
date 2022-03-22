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
 
const int N = 123456+5;
const LL INF = 1e13;
const int mod = 1e9+7;
const LL MXP = 1e10;
/**
**/


// product use map to save memory
LL dp[15][120][120][2][2];
string s;

LL dfs(int i, int p, int digit, bool bound=true, bool lz=true) {
    // if (digit < 0) return 0; // prune
    if (i == s.size()) return digit == 0 && p == 1;

    int r = bound ? s[i]-'0' : 9;
    LL &res = dp[i][p][digit][bound][lz];
    if (res != -1) return res;

    res = 0;
    for (int d = 0; d <= r; ++d) {
        bool nbound = bound && s[i]-'0' == d;
        bool nlz = lz && d == 0;
        if (nlz)
            res += dfs(i+1, p, digit, false, nlz);
        else
            res += dfs(i+1, p/__gcd(p, d), digit-d, nbound, nlz);
    }
    return res;
}

LL cal(LL x) {
    LL res = 0;
    for (int i = 1; i <= 9*s.size(); ++i) {
        memset(dp, -1, sizeof dp);
        res += dfs(0, i, i, 1, 1);
    }
    return res;
}

void solve(int T) {
    cout << "Case #" << T+1 << ": ";

    LL l, r;
    cin >> l >> r;
    
    // goal: compute func(r) - func(l-1)
    // digit dp, maximum sum of digit 12*9 -> 108
    // dp[i][product][sum of digit][bound][leading_zero]
    
    if (l == 1) {
        s = to_string(r);
        cout << cal(r) << "\n";
        return;
    }

    l--;
    s = to_string(l);
    LL funcL = cal(l);
    s = to_string(r);
    LL funcR = cal(r);
    cout << funcR - funcL << "\n";
}   

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    louisfghbvc
        solve(tt);
    return 0;
}
