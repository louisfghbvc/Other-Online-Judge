// Tree to array. and use euler tour down to array and array tour update query.
// O(N). Two case. one is a is father than b. else. if online method can use bit tree.
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

const int N = 2e5+5;

vi g[N];
int in[N], out[N], ts = 0;

void dfs(int u, int p = -1){
    in[u] = ++ts;
    for(int v: g[u]) if(v != p)
        dfs(v, u);
    out[u] = ts;
}

LL pre[2*N];

void solve(){
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; ++i) g[i].clear();

    vector<ii> edge;
    for(int i = 0; i+1 < n; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edge.push_back({u, v});
    }

    dfs(1);

    cin >> q;
    int t, e, x;
    while(q--){
        cin >> t >> e >> x;
        int a = edge[e-1].first, b = edge[e-1].second;
        if(t == 1){
            if(in[a] < in[b]){
                pre[1] += x;
                pre[in[b]] -= x;
                pre[out[b]+1] += x;
            }
            else{
                pre[in[a]] += x;
                pre[out[a]+1] -= x;
            }
        }
        else{
            if(in[b] < in[a]){
                pre[1] += x;
                pre[in[a]] -= x;
                pre[out[a]+1] += x;
            }
            else{
                pre[in[b]] += x;
                pre[out[b]+1] -= x;
            }
        }
    }

    for(int i = 1; i < 2*N; ++i)
        pre[i] += pre[i-1];

    for(int i = 1; i <= n; ++i)
        cout << pre[in[i]] << "\n";

}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}


// another method. O(N). dfs and dfs, lazy propagation. use dep to do that.
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

const int N = 2e5+5;

vi g[N];
int dep[N];
LL val[N];

void dfs(int u, int p = 0){
    for(int v: g[u]) if(v != p){
        dep[v] = dep[u]+1;
        dfs(v, u);
    }
}

void down(int u, int p = 0){
    for(int v: g[u]) if(v != p){
        val[v] += val[u];
        down(v, u);
    }
}

void solve(){
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; ++i) g[i].clear();

    vector<ii> edge;
    for(int i = 0; i+1 < n; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edge.push_back({u, v});
    }

    dfs(1);

    cin >> q;
    int t, e, x;
    while(q--){
        cin >> t >> e >> x;
        int a = edge[e-1].first, b = edge[e-1].second;
        if(t == 2) swap(a, b);
        if(dep[a] <= dep[b]){
            val[1] += x;
            val[b] -= x;
        }
        else{
            val[a] += x;
        }
    }

    down(1);
    for(int i = 1; i <= n; ++i)
        cout << val[i] << "\n";

}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
