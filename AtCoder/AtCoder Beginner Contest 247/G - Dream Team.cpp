/**                                          
 __         ______     __  __     __     ______     ______   ______     __  __     ______     __   __   ______    
/\ \       /\  __ \   /\ \/\ \   /\ \   /\  ___\   /\  ___\ /\  ___\   /\ \_\ \   /\  == \   /\ \ / /  /\  ___\   
\ \ \____  \ \ \/\ \  \ \ \_\ \  \ \ \  \ \___  \  \ \  __\ \ \ \__ \  \ \  __ \  \ \  __<   \ \ \'/   \ \ \____  
 \ \_____\  \ \_____\  \ \_____\  \ \_\  \/\_____\  \ \_\    \ \_____\  \ \_\ \_\  \ \_____\  \ \__|    \ \_____\ 
  \/_____/   \/_____/   \/_____/   \/_/   \/_____/   \/_/     \/_____/   \/_/\/_/   \/_____/   \/_/      \/_____/                                       
**/
#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(All(x)); x.erase(unique(All(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/
 
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }
 
const int N = 150+5;
const LL INF = 1e13;
const int mod = 998244353;
const LL MXP = 1e10;
/**
**/

template<size_t N, typename C=int, typename W=int>
struct mcmf {
    struct edge {
        int v, v_id;
        C c; // flow
        W w; // weight
        edge (int v, int v_id, C c, W w) : v(v), v_id(v_id), c(c), w(w) {}
    };

    vector<edge> g[N];
    typename vector<edge>::iterator idx[N];
    int pre[N]; // parent
    W d[N], h[N]; // dis, prime-dual alg
    bool visit[N];
    int n;
    mcmf (int n) : n(n) {}

    void add_edge(int x, int y, C c, W w) {
        g[x].emplace_back(y, g[y].size(), c, w);
        g[y].emplace_back(x, g[x].size() - 1, 0, -w);
    }

    bool dijkstra(int s, int t) {
        priority_queue<pair<W, int>, vector<pair<W, int>>, greater<pair<W, int>>> pq; // weight, u
        fill(pre, pre+n, -1);
        fill(d, d+n, numeric_limits<W>::max() / 2);
        d[s] = 0;
        pq.push({d[s], s});
        while (pq.size()) {
            auto [dd, u] = pq.top(); pq.pop();
            if (d[u] != dd) continue;
            for (auto it = g[u].begin(); it != g[u].end(); ++it) {
                if (it->c && d[it->v] + h[it->v] > d[u] + it->w + h[u]) {
                    d[it->v] = d[u] + it->w + h[u] - h[it->v]; // note: w + h[u] - h[v] >= 0
                    pre[it->v] = u;
                    idx[it->v] = it;
                    pq.push({d[it->v], it->v});
                }
            }
        }
        return pre[t] >= 0;
    }

    vector<W> solve(int s, int t) { 
        vector<W> res;
        fill(h, h + n, 0);
        W sum = 0;
        while (dijkstra(s, t)) {
            for (int i = 0; i < n; ++i) h[i] += pre[i] < 0 ? 0 : d[i];
            C aug = 1;
            for (int i = t; pre[i] != -1; i = pre[i]) {
                idx[i]->c -= aug;
                g[idx[i]->v][idx[i]->v_id].c += aug;
                sum += idx[i]->w; 
            }
            res.push_back(sum);
        }
        return res;
    }
};

void solve(int T) {
    int n;
    cin >> n;

    vector<array<int, 3>> arr(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> arr[i][j];

    // goal: maximum sum that is dream team

    // observe: k maximum is 150
    // use mcmf

    vector<vi> g(150, vi(150));
    for (int i = 0; i < n; ++i) {
        LL x = arr[i][0], y = arr[i][1], c = arr[i][2];
        --x, --y;
        g[x][y] = max(g[x][y], c);
    }

    const int N = 150;
    mcmf<N * 2 + 2, LL, LL> flow(N * 2 + 2);
    int s = N*2, t = s+1; // dummy node

    for (int i = 0; i < N; ++i) {
        flow.add_edge(s, i, 1, 0);
        flow.add_edge(N+i, t, 1, 0);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (g[i][j]) {
                flow.add_edge(i, N+j, 1, -g[i][j]);
            }
        }
    }

    auto res = flow.solve(s, t);
    cout << sz(res) << "\n";
    for (auto &x: res)
        cout << -x << '\n';
}   

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
