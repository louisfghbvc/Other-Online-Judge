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

const int N = 400 + 5;
const LL INF = LLONG_MAX / 2;
const int mod = 1e9+7;
/**
Read problem statement carefully

FUCK!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Misunderstanding the problem statement...
only allowed to pass city 1~K.... So no need to pass city 1~K can also get shortest path.
pass ---------------------- pass mean go after 1->2. doesn't pass 1 and 2.... 1>2>3. pass 2
.
.
.
So just floyd warshall
**/


void solve(int T){
    int n, m;
    cin >> n >> m;

    vector<vi> g(n+1, vi(n+1, INF));

    for(int i = 0; i < m; ++i){
        LL a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
    }

    for(int i = 1; i <= n; ++i) g[i][i] = 0;

    LL res = 0;
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                if(g[i][j] != INF) res += g[i][j];
            }
        }
    }
    cout << res << "\n";
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
