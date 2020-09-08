// From 3 direction.
// Simple dp.

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

void solve(){
    LL n, a, b, c;
    cin >> n;
    vi dp(3);
    for(int i = 0; i < 3; ++i) cin >> dp[i];

    for(int i = 1; i < n; ++i){
        cin >> a >> b >> c;
        vi prev = dp;
        dp[0] = max({prev[0], prev[1]+a, prev[2]+a});
        dp[1] = max({prev[1], prev[0]+b, prev[2]+b});
        dp[2] = max({prev[2], prev[0]+c, prev[1]+c});
    }

    cout << max({dp[0], dp[1], dp[2]}) << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
