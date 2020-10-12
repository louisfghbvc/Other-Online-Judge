// Prefix. I misunderstand the statement...
// So when a lamp light, all left right up down will light until edge or '#'.
// and other is idepedent.
// so self light. (2^cnt-1) * 2^(k-cnt). where cnt is 1+u+d+l+r. k is total lamp

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

const int mod = 1e9 + 7;
const int N = 2e3+5;
char g[N][N];
int dir[N][N][4];

LL fpow(LL a, int b){
    LL res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    int h, w;
    cin >> h >> w;
    int k = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; ++j){
            cin >> g[i][j];
            k += g[i][j] == '.';
        }
    }

    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; ++j){
            if(g[i][j] == '.'){
                if(g[i][j-1] == '.') dir[i][j][0] = 1+dir[i][j-1][0];
                if(g[i-1][j] == '.') dir[i][j][1] = 1+dir[i-1][j][1];
            }
        }
    }

    for(int i = h; i >= 1; i--){
        for(int j = w; j >= 1; --j){
            if(g[i][j] == '.'){
                if(g[i][j+1] == '.') dir[i][j][2] = 1+dir[i][j+1][2];
                if(g[i+1][j] == '.') dir[i][j][3] = 1+dir[i+1][j][3];
            }
        }
    }

    LL ans = 0;
    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= w; ++j){
            if(g[i][j] == '.'){
                int cnt = dir[i][j][0]+dir[i][j][1]+dir[i][j][2]+dir[i][j][3]+1;
                ans = ans + (fpow(2, cnt)-1)*(fpow(2, k-cnt))%mod;
                ans %= mod;
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
