// BFS. O(N*(N+M)).
// can use dijkstra. more fast.

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
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully
4 5
1 1 100
1 2 5
2 3 5
3 1 15
4 3 20
**/

int g[N][N];
vi gp[N];
int dis[N];

LL bfs(int s, int t){
    memset(dis, 0x3f, sizeof dis);
    queue<pair<int, bool>> q;
    q.push({s, false});
    while(q.size()){
        int u = q.front().first;
        bool ft = q.front().second;
        q.pop();
        for(int v: gp[u]){
            int get = !ft ? 0 : dis[u];
            if(dis[v] > get + g[u][v]){
                dis[v] = get + g[u][v];
                q.push({v, 1});
            }
        }
    }
    return dis[t];
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            g[i][j] = 1e9;

    for(int i = 0, u, v, w; i < m; i++){
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        gp[u].push_back(v);
    }

    for(int i = 1; i <= n; ++i){
        int ddd = bfs(i, i);
        if(ddd == inf) cout << -1 << "\n";
        else cout << ddd << "\n";
    }

}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}

/**
Enjoy the problem.
**/
