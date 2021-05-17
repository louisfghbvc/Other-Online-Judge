#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
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
const int INF = 0x3f3f3f3f;
/**
Read problem statement carefully


**/

char g[N][N];

int h, w;
LL dp[N][N];
bool vis[N][N];

LL dfs(int x, int y, bool ta = 1){
    if(x == h-1 && y == w-1) return 0;
    if(vis[x][y]) return dp[x][y];
    LL res = -1e9;
    if(x+1 < h){
        res = max(res, (g[x+1][y] == '+' ? 1 : -1) - dfs(x+1, y, 0));
    }
    if(y+1 < w){
        res = max(res, (g[x][y+1] == '+' ? 1 : -1) - dfs(x, y+1, 0));
    }
    vis[x][y] = 1;
    // cout << res << "\n";
    return dp[x][y] = res;
}

void solve(int n){
    cin >> h >> w;
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            cin >> g[i][j];

    LL game = dfs(0, 0);
    if(game > 0){
        cout << "Takahashi\n";
    }
    else if(game == 0){
        cout << "Draw\n";
    }
    else cout << "Aoki\n";
}

int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    
    return 0;

}

/**
Enjoy the problem.
**/
