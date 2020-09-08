// Just From two dir. if grid[i][j] = '#', dp[i][j] = '0'
// O(HW)
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

const int mod = 1e9+7;
const int N = 1e3+5;

char grid[N][N];
LL dp[N][N];

void solve(){
    int h, w;
    cin >> h >> w;
    for(int i = 1; i <= h; ++i)
        for(int j = 1; j <= w; ++j)
            cin >> grid[i][j];

    memset(dp, 0, sizeof dp);
    dp[1][1] = 1;
    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= w; ++j){
            if(grid[i][j] == '.'){
                dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1]) % mod;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }


    cout << dp[h][w] << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
