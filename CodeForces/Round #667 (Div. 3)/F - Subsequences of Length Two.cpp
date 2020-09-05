// O(N^3) dp, wow, impressive. hard to think, but code is really simple.
// because string t == 2. so just some case.
// and transition is 3 case. no change. change to T0 or T1. so cnt subsqence is just cnt T0.

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define vt vector
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

LL dp[205][205][205];
LL n;
string s, t;

LL help(int position, int nT0, int k){
    if(position >= n) return 0;
    if(dp[position][nT0][k] != -1) return dp[position][nT0][k];
    LL ans = 0;
    // no change
    ans = help(position+1, nT0, k);
    // make T0
    int cost = s[position] == t[0] ? 0 : 1;
    if(k >= cost)
        ans = max(ans, help(position+1, nT0+1, k-cost));
    // make T1
    cost = s[position] == t[1] ? 0 : 1;
    if(k >= cost)
        ans = max(ans, nT0 + help(position+1, nT0, k-cost));
    return dp[position][nT0][k] = ans;
}

void solve(){
    LL k;
    cin >> n >> k;
    cin >> s >> t;
    memset(dp, -1, sizeof dp);
    if(t[0] == t[1]){
        LL cnt = 0;
        for(char c: s) if(c == t[0]) cnt++;
        cnt += k;
        cnt = min(n, cnt);
        cout << cnt*(cnt-1)/2 << "\n";
    }
    else{
        cout << help(0, 0, k) << "\n";
    }
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
