// use kruscal's algorithm. O(MlogM).
const int N = 1e5+5;
int p[N];

int find(int x){
    return p[x] < 0 ? x : p[x] = find(p[x]);
}

struct edge{
    int a, b, c;
    bool operator<(const edge & e2) const {
        return c < e2.c;
    }
};

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    vector<edge> e;
    for(int i = 1; i <= n; ++i) e.push_back({0, i, c_lib});
    for(auto &road : cities){
        e.push_back({road[0], road[1], c_road});
    }
    sort(e.begin(), e.end());
    memset(p, -1, sizeof p);
    long res = 0;
    for(int i = 0; i < e.size(); ++i){
        int a = find(e[i].a), b = find(e[i].b), c = e[i].c;
        if(a != b){
            p[b] = a;
            res += c;
        }
    }
    return res;
}

// Just dfs. O(N). each component will be  c*c_lib or c_road(c-1) + c_lib.
// easy to think greedy.
const int N = 1e5+5;
vector<int> g[N];
bool vis[N];

void dfs(int u, int &c){
    c++;
    vis[u] = 1;
    for(int v: g[u]){
        if(!vis[v]) dfs(v, c);
    }
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    for(int i = 1; i <= n; ++i) g[i].clear();
    memset(vis, 0, sizeof vis);

    for(auto &e: cities){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }

    long res = 0;

    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            int component = 0;
            dfs(i, component);
            res += min((long)c_lib*component, (long)c_lib + (long)c_road * (component-1));
        }
    }

    return res;
}
