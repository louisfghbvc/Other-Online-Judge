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

const int N = 55;
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully
**/

bool used[16][16];
int h, w;
LL dfs(int x, int y, int a, int b){
    if(a < 0 || b < 0) return 0;
    if(y == w) y = 0, x++;
    if(x == h) return 1;
    if(used[x][y]) return dfs(x, y+1, a, b);
    used[x][y] = 1;
    LL res = 0;
    res += dfs(x, y+1, a, b-1);
    if(y+1 < w && !used[x][y+1]){
        used[x][y+1] = 1;
        res += dfs(x, y+1, a-1, b);
        used[x][y+1] = 0;
    }
    if(x+1 < h && !used[x+1][y]){
        used[x+1][y] = 1;
        res += dfs(x, y+1, a-1, b);
        used[x+1][y] = 0;
    }
    used[x][y] = 0;
    return res;
}

void solve(){
    int a, b;
    cin >> h >> w >> a >> b;
    cout << dfs(0, 0, a, b) << "\n";
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
