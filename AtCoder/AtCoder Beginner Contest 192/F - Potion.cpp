// Tricky Dp.
// Enum all size K.
// and tranfer like bag. enum all number and mod.

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

const int N = 1e2+5;
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully
sum + len*y == x
**/

LL A[N];
LL dp[N][N];
LL x, n;
LL ans = 5e18;

LL f(int num) {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = num - 1; j >= 0; j--) {
            for(int k = 0; k < num; k++) {
                if(dp[j][k] == -1)continue;
                dp[j + 1][(k + A[i]) % num] = max(dp[j + 1][(k + A[i]) % num], dp[j][k] + A[i]);
            }
        }
    }
    if(dp[num][x % num] != -1 && dp[num][x % num] <= x) {
        return (x - dp[num][x % num]) / num;
    }
    return 5e18;
}

void solve(){
    cin >> n >> x;
    for(int i = 0; i < n; ++i){
        cin >> A[i];
    }
    for(int i = 1; i <= n; i++) {
        ans = min(ans, f(i));
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

/**
Enjoy the problem.
**/
