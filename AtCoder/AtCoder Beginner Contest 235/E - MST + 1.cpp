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
 
const int N = 2e5+5;
const LL INF = 1e13;
const int mod = 998244353;
const LL MXP = 1e10;
/**
**/

struct edge{
    int a, b, c;
    int idx = -1;
    bool operator<(edge& o){
        return c < o.c;
    }
};

int p[N];
int find(int x){
    return p[x] < 0 ? x : p[x] = find(p[x]);
}
bool uni(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return false;
    p[y] = x;
    return true;
}
bool can(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return false;
    return true;
}

void solve(int _){
    memset(p, -1, sizeof p);

    int n, m, q;
    cin >> n >> m >> q;

    vector<edge> arr;
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({a, b, c, -1});
    }

    for(int i = 0; i < q; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({a, b, c, i});
    }

    sort(All(arr));

    vector<bool> ans(q);
    for(auto&e: arr){
        if(e.idx != -1){
            if(can(e.a, e.b)){
                ans[e.idx] = true;
            }
        }
        else uni(e.a, e.b);
    }

    for(int i = 0; i < ans.size(); ++i)
        cout << (ans[i] ? "Yes\n" : "No\n");
}

int main()
{
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
