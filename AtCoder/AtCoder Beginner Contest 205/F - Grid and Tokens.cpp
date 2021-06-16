#include <bits/stdc++.h>

// #pragma GCC optimize("O3")
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

struct edge{
    int v, c;
    edge(int v, int c) : v(v), c(c) {}
};

template<size_t N>
struct max_flow{
    vector<int> g[N]; // graph, mapping edge id
    vector<edge> E; // edge array
    int d[N]; // by bfs level order
    int n;

    max_flow(int n){
        this->n = n;
        for(int i = 0; i < n; ++i) g[i].clear();
    }

    void add_edge(int u, int v, int c){
        g[u].emplace_back(E.size());
        E.emplace_back(edge(v, c));

        g[v].emplace_back(E.size());
        E.emplace_back(edge(u, 0));
    }
    
    int augment(int u, int t, int flow){
        if(u == t) return flow;

        for(int eid: g[u]){
            int v = E[eid].v, c = E[eid].c;
            if(d[v] != d[u]+1 || c == 0) continue;
            c = augment(v, t, min(flow, c));
            if(c > 0){
                E[eid].c -= c; // find flow
                E[eid^1].c += c;
                return c;
            }
        }
        d[u] = -1;
        return 0; // fail
    }

    bool bfs(int s, int t){
        memset(d, -1, sizeof d);
        queue<int> q;
        q.push(s);
        d[s] = 0;
        while(q.size()){
            int u = q.front(); q.pop();
            for(int eid : g[u]){
                if(d[E[eid].v] == -1 && E[eid].c){
                    d[E[eid].v] = d[u]+1;
                    q.push(E[eid].v);
                }
            }
        }
        return d[t] != -1;
    };

    int dinic(int s, int t){
        int res = 0;
        while(bfs(s, t)){
            while( int f = augment(s, t, INT_MAX) ){
                res += f;
            }
        }
        return res;
    }
};

int get_id(){
    static int id = -1;
    id++;
    return id;
}

void solve(int T){
    int h, w, n;
    cin >> h >> w >> n;

    int s = get_id();
    int t = get_id();
    
    vi A(n), B(n), C(n), D(n);
    for(int i = 0; i < n; ++i){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        A[i]--, B[i]--;
    }

    vi row(h), col(w); // row id, col id;
    for(int i = 0; i < h; ++i)
        row[i] = get_id();
    for(int i = 0; i < w; ++i)
        col[i] = get_id();

    vi coreR(n), coreC(n); // mapping row to bottleneck, bottleneck to col
    for(int i = 0; i < n; ++i){
        coreR[i] = get_id();
        coreC[i] = get_id();
    }

    max_flow<500> flow(get_id());
    for(int i = 0; i < h; ++i)
        flow.add_edge(s, row[i], 1);
    for(int i = 0; i < w; ++i)
        flow.add_edge(col[i], t, 1);

    for(int i = 0; i < n; ++i){
        for(int r = A[i]; r < C[i]; ++r)
            flow.add_edge(row[r], coreR[i], 1);
        flow.add_edge(coreR[i], coreC[i], 1);
        for(int c = B[i]; c < D[i]; ++c)
            flow.add_edge(coreC[i], col[c], 1);
    }

    cout << flow.dinic(s, t) << "\n";
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
