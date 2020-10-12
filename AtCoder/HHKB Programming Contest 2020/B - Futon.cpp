// count adjacent.
// O(N^2).

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<int> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 1e3+5;

void solve(){
    int h, w;
    cin >> h >> w;
    char g[h+2][w+2];
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            cin >> g[i][j];
    int cnt = 0;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j+1 < w; ++j){
            if(g[i][j] == '.' && g[i][j] == g[i][j+1]) cnt++;
        }
    }
    for(int j = 0; j < w; ++j){
        for(int i = 0; i+1 < h; ++i){
            if(g[i][j] == '.' && g[i][j] == g[i+1][j]) cnt++;
        }
    }
    cout << cnt << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
