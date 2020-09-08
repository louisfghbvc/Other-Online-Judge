// O(NW). Reverse put cuz 01bag. not duplicate put.

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

const int N = 1e5+5;
LL dp[N];
LL cost[105], val[105];

void solve(){
    int n, w;
    cin >> n >> w;
    for(int i = 0; i < n; ++i) cin >> cost[i] >> val[i];

    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++i){
        for(int j = w; j >= cost[i-1]; --j)
            dp[j] = max(dp[j], dp[j-cost[i-1]] + val[i-1]);
    }

    cout << dp[w] << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
