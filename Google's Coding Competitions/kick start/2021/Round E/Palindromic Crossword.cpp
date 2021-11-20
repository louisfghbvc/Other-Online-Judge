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
 
const int N = 2e6+5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
**/

int p[N];
int find(int x){
    return p[x] < 0 ? x : p[x] = find(p[x]);
}
void uni(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    p[y] = x;
}

void solve(int T){
    memset(p, -1, sizeof p);
    printf("Case #%d: ", ++T);

    int n, m;
    cin >> n >> m;
    char g[n+2][m+2];
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> g[i][j];
    
    // left to right
    for(int i = 0; i < n; ++i){
        bool block = true; // #
        for(int j = 0; j < m; j++){
            if(g[i][j] == '#') block = true;
            else{
                if(block){
                    block = false;
                    int nj = j;
                    while(nj < m && g[i][nj] != '#') nj++;
                    // [j, nj)
                    for(int k1 = j, k2 = nj-1; k1 < k2; ++k1, --k2)
                        uni(i * m + k1, i * m + k2);
                    j = nj-1;
                }
            } 
        }
    }

    // up to down
    for(int j = 0; j < m; ++j){
        bool block = true; // #
        for(int i = 0; i < n; i++){
            if(g[i][j] == '#') block = true;
            else{
                if(block){
                    block = false;
                    int ni = i;
                    while(ni < n && g[ni][j] != '#') ni++;
                    // [i, ni)
                    for(int k1 = i, k2 = ni-1; k1 < k2; ++k1, --k2)
                        uni(k1 * m + j, k2 * m + j);
                    i = ni-1;
                }
            } 
        }
    }

    // fill the word
    vector<set<char>> ind(n * m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(g[i][j] == '#') continue;
            ind[find(i * m + j)].insert(g[i][j]);
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(g[i][j] == '#') continue;
            if(g[i][j] == '.'){
                g[i][j] = *ind[find(i * m + j)].rbegin();
                cnt += g[i][j] != '.';
            }
        }
    }

    cout << cnt << "\n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << g[i][j];
        }
        cout << "\n";
    }
    
}   
 
int main()
{
    // Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    louisfghbvc
        solve(tt);
    return 0;
}
