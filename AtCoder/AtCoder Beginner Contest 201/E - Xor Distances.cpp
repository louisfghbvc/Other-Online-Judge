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

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 2e5+5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully

**/



void solve(int n){
    cin >> n;

    vector<vector<ii>> g(n);

    for(LL i = 0, u, v, w; i+1 < n; ++i){
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vi dis(n, -1);
    dis[0] = 0;
    queue<int> q;
    q.push(0);

    while(q.size()){
        int u = q.front(); q.pop();
        for(auto &[v, w]: g[u]){
            if(dis[v] == -1){
                dis[v] = dis[u] ^ w;
                q.push(v);
            }
        }
    }

    LL res = 0;
    for(int i = 0; i < 60; ++i){
        LL cnt[2] = {};
        for(int j = 0; j < n; ++j){
            cnt[dis[j]>>i&1]++;
        }
        res += (1LL<<i) % mod * cnt[0] % mod * cnt[1];
        res %= mod;
    }

    cout << res << "\n";
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
