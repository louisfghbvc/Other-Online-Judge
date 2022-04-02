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
 
const int N = 1500+5;
const LL INF = 1e13;
const int mod = 998244353;
const LL MXP = 1e10;
/**
**/

const int dir[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

void solve(int T) {
    int n;
    cin >> n;

    vector<string> grid(n);
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    cin >> grid;

    // goal: minimum move to (sx, sy) -> (tx, ty)
    // use 0-1 bfs to simplfied the problem
    // since same diagonal will not cost value

    deque<array<int, 3>> q; // px, py, i
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(4, 1e9)));
    --sx, --sy;
    --tx, --ty;

    if (grid[sx][sy] == '#' || grid[tx][ty] == '#') {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = sx + dir[i][0], ny = sy + dir[i][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == '#') continue;
        dp[nx][ny][i] = 1;
        q.push_back({nx, ny, i});
    }

    while (q.size()) {
        auto [x, y, dr] = q.front(); q.pop_front();

        if (x == tx && y == ty) {
            cout << dp[x][y][dr] << "\n";
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == '#') continue;
            int cost = i == dr ? 0 : 1;
            if (dp[nx][ny][i] > dp[x][y][dr] + cost) {
                dp[nx][ny][i] = dp[x][y][dr] + cost;
                if (cost)
                    q.push_back({nx, ny, i});
                else
                    q.push_front({nx, ny, i});
            }
        }
    }
    
    cout << -1 << "\n";
}   

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
