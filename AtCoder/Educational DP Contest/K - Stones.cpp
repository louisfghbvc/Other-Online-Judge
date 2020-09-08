// O(NK).
// main idea. if choose arr[i] can make dfs false. this state is win.

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

const int K = 1e5+5;
int arr[105];
int dp[K];
int n, k;

int dfs(int remain){
    if(dp[remain] != -1) return dp[remain];
    bool res = 0;
    for(int i = 0; i < n; ++i){
        if(remain >= arr[i]) res |= (dfs(remain-arr[i]) == 0);
    }
    return dp[remain] = res;
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    memset(dp, -1, sizeof dp);

    cout << (dfs(k)==1 ? "First": "Second") << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
