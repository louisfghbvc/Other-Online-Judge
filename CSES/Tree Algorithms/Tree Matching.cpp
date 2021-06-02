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

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

vi g[N];

int pr = 0;
int dfs(int u = 1, int p = -1){
    int res = 1;
    for(int v: g[u]){
        if(v != p){
            int sub = dfs(v, u);
            if(sub && res){
                res--;
                pr++;
            }
        }
    }
    return res;
}

void solve(int T){
    int n;
    cin >> n;
    for(int i = 0; i+1 < n; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs();

    cout << pr << "\n";
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
