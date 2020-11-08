// Well. so similar to other problems...
// Today is not my day. Tired.
// Can not change input. and like prefix. rolling.
// Conv 4 direction. finally. count all u[i][j] == 1.
// O(HW).

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

const int N = 1500+5;

int g[N][N];
int u[N][N];

void solve(){
    memset(g, 0, sizeof g);
    memset(u, 0, sizeof u);

    int h, w, n, m;
    cin >> h >> w >> n >> m;
    int x, y;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        g[x][y] = 1;
    }
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        g[x][y] = -1;
    }

    for(int i = 1; i <= h; ++i){ // right
        bool ok = 0;
        for(int j = 1; j <= w; ++j){
            if(g[i][j] == 1) ok = 1;
            else if(g[i][j] == -1) ok = 0;
            if(ok) u[i][j] = 1;
        }
    }

    for(int j = 1; j <= w; ++j){ // down
        bool ok = 0;
        for(int i = 1; i <= h; ++i){
            if(g[i][j] == 1) ok = 1;
            else if(g[i][j] == -1) ok = 0;
            if(ok) u[i][j] = 1;
        }
    }

    for(int j = w; j >= 1; --j){ // up
        bool ok = 0;
        for(int i = h; i >= 1; --i){
            if(g[i][j] == 1) ok = 1;
            else if(g[i][j] == -1) ok = 0;
            if(ok) u[i][j] = 1;
        }
    }

    for(int i = h; i >= 1; --i){ // left
        bool ok = 0;
        for(int j = w; j >= 1; --j){
            if(g[i][j] == 1) ok = 1;
            else if(g[i][j] == -1) ok = 0;
            if(ok) u[i][j] = 1;
        }
    }

    int res = 0;
    for(int i = 1; i <= h; ++i)
        for(int j = 1; j <= w; ++j)
            res += u[i][j];

    cout << res << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
