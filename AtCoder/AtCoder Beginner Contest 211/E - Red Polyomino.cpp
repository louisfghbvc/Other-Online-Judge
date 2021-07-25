/**   super fast backtracking. 29ms                                       
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
 
const int N = 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
**/

vector<string> g;
int n;
int ans = 0;
set<vector<string>> st;

const int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

bool valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int k){
    // if(st.count(g)) return;
    // st.insert(g);

    if(k == 0){
        ans++;
        return;
    }
    vector<ii> nxt;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(g[i][j] != '.') continue;
            bool flag = 0;
            for(int q = 0; q < 4; ++q){
                int nx = i+dir[q][0], ny = j+dir[q][1];
                if(valid(nx, ny) && g[nx][ny] == '@'){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                g[i][j] = '@';
                dfs(k-1);
                g[i][j] = '#';
                nxt.push_back({i, j});
            }
        }
    }
    for(auto &[x, y]: nxt){ // this is tricky. so after going. u need to recover.
        g[x][y] = '.';
    }
}

void solve(int T){
    int k;
    cin >> n >> k;

    g.resize(n);
    for(int i = 0; i < n; ++i)
        cin >> g[i];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(g[i][j] == '.'){
                g[i][j] = '@';
                dfs(k-1);
                g[i][j] = '#';
            }
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

// Another appoach. is use set to check duplicate so u just do standard backtracking
// u no need to color to '#'. just recover to '.' and use set.
// 500ms
