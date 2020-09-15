// if use long long TLE, because cost big.
// so use int, the memory is ok. also can use iterate.
// O(N).

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 2e5+5;
int dp[N][2];
int boss[N];
int n;

int dfs(int i, bool me){
    if(i >= n) return 0;
    if(dp[i][me] != -1) return dp[i][me];
    int res = 1e9;
    if(!me){
        res = min(res, boss[i] + dfs(i+1, 1));
        if(i+1 < n) res = min(res, boss[i] + boss[i+1] + dfs(i+2, 1));
    }
    else{
        res = min(res, dfs(i+1, 0));
        if(i+1 < n) res = min(res, dfs(i+2, 0));
    }
    return dp[i][me] = res;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> boss[i];
    memset(dp, -1, sizeof dp);
    cout << dfs(0, 0) << "\n";
}

int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
