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

Tricky part is prune.

e.g cur == 'L'. check this, may cause connected components.
o o o ...
o  'x' . ...
'o' x 'o' ...
   'x'
**/


bool vis[7][7];
int ans = 0;
string s;

bool valid(int x, int y){
    return x >= 0 && x <= 6 && y >= 0 && y <= 6 && !vis[x][y];
}

void dfs(int x, int y,  int i = 0){
    if(x == 6 && y == 0){
        if(i == 48) ans++;
        return;
    }

    vis[x][y] = 1;
    if(s[i] == '?' || s[i] == 'U'){
        if(x && !vis[x-1][y])
            if(! (!valid(x-2, y) && valid(x-1, y-1) && valid(x-1, y+1)) )
                dfs(x-1, y, i+1);
    }
    if(s[i] == '?' || s[i] == 'D'){
        if(x < 6 && !vis[x+1][y])
            if(! (!valid(x+2, y) && valid(x+1, y-1) && valid(x+1, y+1)) )
                dfs(x+1, y, i+1);
    }
    if(s[i] == '?' || s[i] == 'L'){
        if(y && !vis[x][y-1]){
            if(! (!valid(x, y-2) && valid(x-1, y-1) && valid(x+1, y-1)) )
                dfs(x, y-1, i+1);
        }
    }
    if(s[i] == '?' || s[i] == 'R'){
        if(y < 6 && !vis[x][y+1])
            if(! (!valid(x, y+2) && valid(x-1, y+1) && valid(x+1, y+1)) )
                dfs(x, y+1, i+1);
    }
    vis[x][y] = 0;
}

void solve(int T){
    cin >> s;
    dfs(0, 0);
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

/**
Enjoy the problem.
**/
