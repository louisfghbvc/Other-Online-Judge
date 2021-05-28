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

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const char D[4] = {'U', 'D', 'L', 'R'};

char g[N][N];
bool vis[N][N];
int path[N][N];

int s = 0, e = 0;
int n, m;
void dfs(int x, int y, vector<char> &res){
    if(x * m + y == s){
        reverse(All(res));
        return;
    }
    int d = path[x][y];
    res.push_back(D[d]);
    dfs(x - dir[d][0], y - dir[d][1], res);
}

void solve(int T){
    memset(vis, 0, sizeof vis); 

    cin >> n >> m;    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> g[i][j];
            if(g[i][j] == 'A') s = i*m + j;
            if(g[i][j] == 'B') e = i*m + j;
        }
    }

    queue<int> q; // idx
    q.push(s);
    vis[s / m][s % m] = 1;

    while(q.size()){
        int idx = q.front(); q.pop();
        int x = idx / m, y = idx % m;
        if(idx == e){
            cout << "YES\n";
            vector<char> tmp;
            dfs(x, y, tmp);
            cout << sz(tmp) << "\n";
            for(char &c: tmp)
                cout << c;
            cout << "\n";
            return;
        }
        for(int k = 0; k < 4; ++k){
            int nx = x+dir[k][0], ny = y+dir[k][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '#' || vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            path[nx][ny] = k; // from k dir.
            q.push(nx * m + ny);
        }
    }

    cout << "NO\n";
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
