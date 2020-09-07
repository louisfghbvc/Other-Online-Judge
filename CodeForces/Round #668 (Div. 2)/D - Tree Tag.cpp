// OMG... Just Stick with P.C, 
// this problem is not so hard..
// O(N). just find diameter. if da >= diam/2, says if Alice be middle point can always capture Bob.
// of da >= db/2. can catch.
// or first step the dis[b] <= da. so first catch.
// just dfs...QQ

#include <bits/stdc++.h>
 
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
const int N = 1e5+5;
int dis[N], mx, mxi;
vector<int> g[N];
 
void dfs(int u, int p = -1){
    if(dis[u] > mx){
        mx = dis[u];
        mxi = u;
    }
    for(int v: g[u]){
        if(v != p){
            dis[v] = dis[u]+1;
            dfs(v, u);
        }
    }
}
 
void solve(){
    int n, a, b, da, db, u, v;
    cin >> n >> a >> b >> da >> db;
 
    for(int i = 1; i <= n; ++i) g[i].clear();
 
    for(int i = 0; i < n-1; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    dis[1] = 0;
    mx = 0;
    dfs(1);
 
    dis[mxi] = 0;
    mx = 0;
    dfs(mxi);
 
    if(2 * da >= min(mx, db)){
        cout << "Alice\n";
        return;
    }
 
    dis[a] = 0;
    dfs(a);
 
    if(dis[b] <= da){
        cout << "Alice\n";
        return;
    }
 
    cout << "Bob\n";
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
