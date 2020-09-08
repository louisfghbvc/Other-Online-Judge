// adj merge. last merge must cost pre[r]-pre[l]. so divide each two one pile.

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 405;
LL arr[N];
LL pre[N];
LL dp[N][N];


LL dfs(int l, int r){
    //dbg_out(l, r);
    if(l == r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    LL res = pre[r+1] - pre[l];
    LL mn = 1e14;
    for(int k = l; k < r; ++k){
        mn = min(mn, dfs(l, k) + dfs(k+1, r));
    }
    return dp[l][r] = res + mn;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    pre[0] = 0;
    for(int i = 0; i < n; ++i) pre[i+1] += pre[i] + arr[i];

    memset(dp, -1, sizeof dp);
    cout << dfs(0, n-1) << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
