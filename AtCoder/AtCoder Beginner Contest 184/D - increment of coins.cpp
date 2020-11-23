// because we want to know expected value of operations.
// dp[x][y][z] is excepted value.
// and dp[x][y][z] = 1 + x/(x+y+z)*dp[x+1][y][z] + y/(x+y+z)*dp[x][y+1][z] + z/(x+y+z)*dp[x][y][z+1]
// I understand the E more. Trick.

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

const int N = 100+5;
double dp[N][N][N];
bool vis[N][N][N];

double dfs(int x, int y, int z){
    if(x == 100 || y == 100 || z == 100) return 0.0;
    if(vis[x][y][z]) return dp[x][y][z];
    vis[x][y][z] = 1;
    dp[x][y][z] = 1 + 1.0*x/(x+y+z)*dfs(x+1, y, z) + 1.0*y/(x+y+z)*dfs(x, y+1, z) + 1.0*z/(x+y+z)*dfs(x, y, z+1);
    return dp[x][y][z];
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    printf("%.12f\n", dfs(a, b, c));
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
