// Very Like Problem.
// so first try find build lca.
// and 3 case.
// distance lca is smaller than c. output b
// can goto lca but can not go to b. b Kth-ancestor
// otherwise, a Kth-ancestor.
// O(NlogN).

#include <bits/stdc++.h>
#define Fast cin.tie(0), ios::sync_with_stdio(0)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 3*1e5 +5;
//LL arr[N];

vector<int> g[N];
const int lg = 20;
int dis[N];
int par[N][lg];
int in[N], out[N];
LL n, q, t = 0;

void dfs(int u = 0, int d = 0, int p = 0){
    dis[u] = d;
    in[u] = ++t;
    for(int &v: g[u]){
        if(v != p){
            par[v][0] = u;
            dfs(v, d+1, u);
        }
    }
    out[u] = ++t;
}

bool anc(int x, int y){
    return in[x] <= in[y] && out[x] >= out[y];
}

int lca(int x, int y){
    if(anc(x, y)) return x;
    if(anc(y, x)) return y;

    for(int l = lg-1; l >= 0; --l){
        if(!anc(par[x][l], y))
            x = par[x][l];
    }
    return par[x][0];
}

int kthA(int x, int k){
    for(int l = 0; l <= lg-1; ++l){
        if(k & (1<<l)) x = par[x][l];
    }
    return x;
}

void solve(){

    dfs();
    for(int l = 1; l <= lg-1; ++l){
        for(int i = 0; i < n; ++i){
            par[i][l] = par[par[i][l-1]][l-1];
        }
    }

    cin >> q;
    LL a, b, c;
    for(int i = 0; i < q; ++i){
        cin >> a >> b >> c;
        --a, --b;
        int ac = lca(a, b);
        int d = dis[a] - dis[ac] + dis[b] - dis[ac];
        if(d <= c){
            cout << b+1 << "\n";
        }
        else if(c >= (dis[a]-dis[ac])){
            cout << kthA(b, d-c)+1 << "\n";
        }
        else{
            cout << kthA(a, c)+1 << "\n";
        }
    }
}

int main()
{

    Fast;
    cin >> n;
    LL a, b;
    for(int i = 0; i < n-1; ++i){
        cin >> a >> b;
        a--; b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    solve();

    return 0;
}
