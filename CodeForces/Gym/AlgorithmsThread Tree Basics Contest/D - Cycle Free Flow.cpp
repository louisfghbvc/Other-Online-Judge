// Wow, Very nice problem. so the main idea is record log flow.
// so can use lca, and the distance. and K-jump.

#include <bits/stdc++.h>
#define Fast cin.tie(0), ios::sync_with_stdio(0)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 3*1e5 +5;
const int lg = 20;
LL n, m;

vector<ii> g[N];
ii par[N][lg];
LL dis[N];
LL in[N], out[N], t = 0;

bool anc(LL x, LL y){
    return in[x] <= in[y] && out[x] >= out[y];
}

LL kFlow(LL x, LL k){
    LL flow = 1e9+5;
    for(int l = 0; l < lg; ++l){
        if(k & (1<<l)){
            LL nx = par[x][l].first;
            flow = min(par[x][l].second, flow);
            x = nx;
        }
    }
    return flow;
}

LL lca(LL x, LL y){
    if(anc(x, y)) return x;
    if(anc(y, x)) return y;

    for(int l = lg-1; l >= 0; --l)
        if(!anc(par[x][l].first, y))
            x = par[x][l].first;

    return par[x][0].first;
}

void dfs(LL u = 0, LL d = 0, LL p = 0){
    in[u] = ++t;
    dis[u] = d;
    for(auto pr: g[u]){
        LL v = pr.first, w = pr.second;
        if(v != p){
            par[v][0] = {u, w};
            dfs(v, d+1, u);
        }
    }
    out[u] = ++t;
}

void solve(){
    dfs();
    for(int l = 1; l < lg; ++l){
        for(int k = 0; k < n; ++k){
            par[k][l].first = par[par[k][l-1].first][l-1].first;
            if(!par[k][l-1].second || !par[par[k][l-1].first][l-1].second)
                par[k][l].second = max(par[k][l-1].second, par[par[k][l-1].first][l-1].second);
            else par[k][l].second = min(par[k][l-1].second, par[par[k][l-1].first][l-1].second);
        }
    }
}

void req(){
    LL q, a, b;
    cin >> q;
    while(q--){
        cin >> a >> b;
        --a, --b;
        LL ac = lca(a, b);
        LL k1 = dis[a]-dis[ac];
        LL k2 = dis[b]-dis[ac];
        cout << min(kFlow(a, k1), kFlow(b, k2)) << "\n";
    }
}

int main()
{

    Fast;
    cin >> n >> m;
    LL a, b, w;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> w;
        --a, --b;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    solve();
    req();

    return 0;
}
