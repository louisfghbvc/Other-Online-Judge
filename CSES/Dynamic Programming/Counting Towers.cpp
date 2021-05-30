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

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully

**/

LL dp[N][2]; // 0 1x1 not unit, 1 1x2 unit
void init(){
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i < N; ++i){
        dp[i][0] += dp[i-1][1];
        dp[i][1] += dp[i-1][0];
        dp[i][1] += 2 * dp[i-1][1];
        dp[i][0] += 4 * dp[i-1][0];

        dp[i][1] %= mod;
        dp[i][0] %= mod;
    }
}

void solve(int T){
    int n;
    cin >> n;
    cout << (dp[n][0] + dp[n][1]) % mod << "\n";
}

int main()
{
    init();
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
