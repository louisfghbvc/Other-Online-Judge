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
 
const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int dis[N][N]; // shortest distance to this position
ii from[N][N];
string ans;

int n, m;
queue<ii> q;
bool isA = false; // A move
bool possible = false;

void trace(ii cur){
    ii par = from[cur.first][cur.second];
    if(par.first == 0 || par.second == 0) return;
    if(par.first + 1 == cur.first) ans += 'D';
    if(par.first - 1 == cur.first) ans += 'U';
    if(par.second + 1 == cur.second) ans += 'R';
    if(par.second - 1 == cur.second) ans += 'L';
    trace(par);
}

void check(ii origin, ii nxt){
    if(nxt.first < 1 || nxt.first > n || nxt.second < 1 || nxt.second > m) return;
    if(dis[origin.first][origin.second] + 1 < dis[nxt.first][nxt.second]){
        dis[nxt.first][nxt.second] = dis[origin.first][origin.second] + 1;
        q.push(nxt);
        from[nxt.first][nxt.second] = origin;
    }
}

void bfs(){
    while(sz(q)){
        auto [x, y] = q.front(); q.pop();
        if(isA && (x == 1 || x == n || y == 1 || y == m)){
            possible = true;
            trace({x, y});
            return;
        }
        for(int i = 0; i < 4; ++i){
            int nx = x + dir[i][0], ny = y + dir[i][1];
            check({x, y}, {nx, ny});
        }
    }
}

void solve(int T){
    cin >> n >> m;
    char c;
    int sx, sy;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dis[i][j] = INT_MAX;
            cin >> c;
            if(c == '#') dis[i][j] = 0;
            if(c == 'M') q.push({i, j}), dis[i][j] = 0;
            if(c == 'A') sx = i, sy = j;
        }
    }

    // monster go first
    bfs();

    isA = true;
    dis[sx][sy] = 0;
    from[sx][sy] = {0, 0};
    q.push({sx, sy});
    bfs();

    if(possible){
        cout << "YES\n";
        cout << sz(ans) << "\n";
        reverse(All(ans));
        for(char c: ans)
            cout << c;
        cout << "\n";
    }
    else cout << "NO\n";
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
