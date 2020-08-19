// same as A. but the root may ba a lot.
// so when first dfs find root, and try all dis == mxd, that means root.
// and dfs a random root. and again. record the root.
// use set so check set if in set, mxd + 1, otherwise mxd.
// WA 3 times..
// O(M+N+M+N+N)

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 3*1e5 +5;
//LL arr[N];
vector<int> g[N];
int mx = 0, mxd = 0;
int dis[N];
LL n, a, b;

void dfs(int u, int d = 0, int p = -1){
    if(mxd < d){
        mx = u;
        mxd = d;
    }
    dis[u] = d;
    for(int &v: g[u]){
        if(v == p) continue;
        dfs(v, d+1, u);
    }
}

void solve(){
    dfs(0);
    unordered_set<int> root;
    for(int i = 0; i < n; ++i) if(mxd == dis[i]) root.insert(i);
    mxd = 0;
    memset(dis, 0, sizeof dis);
    dfs(mx);
    for(int i = 0; i < n; ++i) if(mxd == dis[i]) root.insert(i);
    for(int i = 0; i < n; ++i){
        cout << (root.count(i) ? mxd+1: mxd) << "\n";
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n-1; ++i){
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    solve();
    return 0;
}
