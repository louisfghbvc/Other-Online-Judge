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
 
const int N = 2e5+5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
/**
**/

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> g(4, vector<int>(4));

// set g[x,y] to obs
void dfs(int x, int y, int obs){
    if(g[x][y] == obs) return;
    g[x][y] = obs;
    for(int i = 0; i < 4; ++i){
        int nx = x+dir[i][0], ny = y+dir[i][1];
        if(min(nx, ny) < 0 || max(nx, ny) >= 4 || g[nx][ny] == obs) continue;
        dfs(nx, ny, obs);
    }
}

bool check(){
    int cnt = 0;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(g[i][j]){
                cnt++;
                dfs(i, j, 0);
            }
        }
    }
    return cnt == 1;
}

bool nohole(){
    // from 4 edge
    for(int j = 0; j < 4; ++j) dfs(0, j, 1);
    for(int j = 0; j < 4; ++j) dfs(3, j, 1);
    for(int i = 0; i < 4; ++i) dfs(i, 0, 1);
    for(int i = 0; i < 4; ++i) dfs(i, 3, 1);

    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            if(g[i][j] == 0) return false;

    return true;
}

void solve(int T){
    vector<vector<int>> A(4, vector<int>(4));
    cin >> A;

    int ans = 0;

    // enumerate all possible
    for(int i = 0; i < (1<<16); ++i){
        bool ok = 1;
        for(int j = 0; j < 16; ++j){
            int r = j/4, c = j%4;
            if(i >> j & 1){
                g[r][c] = 1;
            }
            else{
                g[r][c] = 0;
                if(A[r][c]){
                    ok = 0; break;
                }
            }
        }
        if(!ok) continue;
        auto tmp = g;
        if(check()){
            g = tmp;
            if(nohole()) ans++;
        }
    }

    cout << ans << "\n";
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
