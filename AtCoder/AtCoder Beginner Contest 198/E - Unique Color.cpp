#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 1e5+5;
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully

**/

vi g[N];
bool good[N];
int color[N];
int mp[N];
int n;

void dfs(int u, int p = -1){
    mp[color[u]]++;
    if(mp[color[u]] == 1) good[u] = 1;
    for(int v: g[u]){
        if(v == p) continue;
        dfs(v, u);
    }
    mp[color[u]]--;
}


void solve(){

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> color[i];

    for(int i = 0, u, v; i < n-1; ++i){
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);

    for(int i = 0; i < n; ++i){
        if(good[i])
            cout << i+1 << "\n";
    }
}

int main()
{

    Fast;
    //louisfghbvc
        solve();
    return 0;
}

/**
Enjoy the problem.
**/
