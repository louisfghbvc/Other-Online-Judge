// Game, Minimax.
// O(N^2).

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

const int N = 3e3+5;
LL arr[N];

LL dp[N][N][2];

LL dfs(int l, int r, bool Taro){
    if(l > r) return 0;
    if(dp[l][r][Taro] != -1) return dp[l][r][Taro];
    LL res = 0;
    if(Taro){
        res = max(arr[l] + dfs(l+1, r, false), arr[r] + dfs(l, r-1, false));
    }
    else{
        res = min(-arr[l] + dfs(l+1, r, true), -arr[r] + dfs(l, r-1, true));
    }
    return dp[l][r][Taro] = res;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    memset(dp, -1, sizeof dp);
    cout << dfs(0, n-1, true) << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
