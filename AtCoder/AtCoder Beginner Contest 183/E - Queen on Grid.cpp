// Prefix dp... oh... need 3 direction prefix. almost done.
// but I only use 1 prefix. so stuck with it.
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

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 2e3+5;
const int mod = 1e9+7;
char g[N][N];
LL dp[4][N][N];

void Add(LL &a, LL b){
    a = (a+b)%mod;
}

void solve(){
    int h, w;
    cin >> h >> w;
    for(int i = 1; i <= h; ++i)
        for(int j = 1; j <= w; ++j)
            cin >> g[i][j];
    for(int k = 0; k < 4; ++k) dp[k][1][1] = 1;

    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= w; ++j){
            if(g[i][j] == '#' || i+j == 2) continue;

            Add(dp[0][i][j], dp[1][i-1][j]);
            Add(dp[0][i][j], dp[2][i][j-1]);
            Add(dp[0][i][j], dp[3][i-1][j-1]);

            Add(dp[1][i][j], dp[1][i-1][j] + dp[0][i][j]);
            Add(dp[2][i][j], dp[2][i][j-1] + dp[0][i][j]);
            Add(dp[3][i][j], dp[3][i-1][j-1] + dp[0][i][j]);
        }
    }

    cout << dp[0][h][w] << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
