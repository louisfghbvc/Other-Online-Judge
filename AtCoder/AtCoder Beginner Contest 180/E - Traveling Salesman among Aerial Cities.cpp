// classic tsp, just use space get time.
// cuz if bf is O(N!).
// now use bitmask make it 2^N

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<int> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 20, inf = 0x3f3f3f3f;
int dp[N][1<<N], n;
int x[N], y[N], z[N];

int edge(int i, int j){
    return abs(x[j] - x[i]) + abs(y[j] - y[i]) + max(0, z[j]-z[i]);
}

int dfs(int vis, int i){
    if(__builtin_popcount(vis) == n) return edge(i, 0);
    if(dp[i][vis] != -1) return dp[i][vis];

    int mn = inf;
    for(int j = 0; j < n; ++j){
        if(j == i || vis & (1<<j)) continue;
        mn = min(dfs(vis|(1<<j), j)+ edge(i, j), mn);
    }
    return dp[i][vis] = mn;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> z[i];
    memset(dp, -1, sizeof dp);
    cout << dfs(1, 0);
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
