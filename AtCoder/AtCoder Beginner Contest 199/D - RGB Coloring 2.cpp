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

const int N = 20+5;
const int INF = 0x3f3f3f3f;
/**
Read problem statement carefully
**/

vi g[N];
vector<vi> component;
LL color[N];
bool vis[N];
int n, m;

void dfs(int u, vi &tmp){
    vis[u] = 1;
    tmp.push_back(u);
    for(int v: g[u]){
        if(!vis[v]){
            dfs(v, tmp);
        }
    }
}

LL solve(vi &tmp, int idx) {
    if (idx == sz(tmp))  return 1;
    LL res = 0;
    for(int i = 1; i <= 3; ++i) {
        color[tmp[idx]] = i;
        bool ok = true;
        for (int v : g[tmp[idx]]) {
            if (color[v] == color[tmp[idx]]) {
                ok = false;
                break;
            }
        }
        if (!ok)  continue;
        res += solve(tmp, idx+1);
    }
    color[tmp[idx]] = 0;
    return res;
}

void solve(int x){

    cin >> n >> m;
    for(int i = 0, a, b; i < m; ++i){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            vi tmp;
            dfs(i, tmp);
            component.push_back(tmp);
        }
    }

    LL ans = 1;
    for(auto &tmp : component){
        ans *= solve(tmp, 0);
    }

    cout << ans << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve(1);
    return 0;
}

/**
Enjoy the problem.
**/
