// each position, you have 3 choice. delete a, delete b, ignore but compute cost if a[i] != b[i].
// O(N^2)

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

const int N = 1e3+5;

int A[N], B[N];
int n, m;
int dp[N][N];

int dfs(int i, int j){
    if(i >= n && j >= m) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int mn = 1e9;
    if(i < n) mn = 1+dfs(i+1, j);
    if(j < m) mn = min(mn, 1+dfs(i, j+1));
    if(i < n && j < m) mn = min(mn, (A[i] != B[j]) + dfs(i+1, j+1));

    return dp[i][j] = mn;
}

void solve(){
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < m; i++) cin >> B[i];
    cout << dfs(0, 0) << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
