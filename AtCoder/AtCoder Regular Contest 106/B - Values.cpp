// can observe that if connected component. can banlance because undirected.
// use DSU. check all component sum is equal.

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

const int N = 2e5+5;
int p[N];
LL sum1[N], sum2[N];

int find(int x){
    return p[x] < 0 ? x : p[x] = find(p[x]);
}

void uni(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    p[y] = x;
}

void solve(){
    memset(p, -1, sizeof p);
    int n, m;
    cin >> n >> m;
    vi a(n), b(n);
    cin >> a >> b;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        uni(u, v);
    }

    for(int i = 0; i < n; ++i){
        int px = find(i);
        sum1[px] += a[i];
        sum2[px] += b[i];
    }

    for(int i = 0; i < n; ++i){
        if(sum1[i] != sum2[i]){
            puts("No");
            return;
        }
    }
    puts("Yes");
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
