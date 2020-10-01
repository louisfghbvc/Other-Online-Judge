// O(NM+C). 
// say dp is move x, and move y. eg. dp[5] = 2, means a point move right 5 and up 2.
// So a, b is robber, c,d is lights.
// so we need x+ai > cj or y+bi > dj, so if x+ai <= cj, must y > dj-bi
// and from back to begin. because if back need y, prev must need y too.
// remember add x. why? dp[x]+x, means point move right x and up dp[x]
// if a point move right x not enough, move right x-1 also not enough. 
// so move right x is decrease. and dp[x] is maintain max. record x+dp[x] minimum. and lazy all scan, a general solution.

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

const int N = 1e6+5;
int dp[N];

void solve(){
    int n, m;
    cin >> n >> m;

    vi a(n), b(n), c(m), d(m);
    for(int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];

    for(int i = 0; i < m; ++i)
        cin >> c[i] >> d[i];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i] > c[j] || b[i] > d[j]) continue;
            dp[c[j]-a[i]] = max(dp[c[j]-a[i]], d[j]-b[i]+1);
        }
    }

    for(int i = N-2; i >= 0; --i)
        dp[i] = max(dp[i], dp[i+1]);

    int ans = INT_MAX;
    for(int i = 0; i < N; ++i)
        ans = min(ans, dp[i]+i);

    cout << ans << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
