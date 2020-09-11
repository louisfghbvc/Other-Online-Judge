// Tricky. remember the precision 10-9.
// two case. dp[i+1][j+1] += p[i] * dp[i][j+1]. positive.
// dp[i+1][j] += (1-p[i]) * dp[i][j]. neg. very simple.
// when build. dont consider the number of positive and negitive. just consider after dp build. then add all dp[n][n/2+1].... dp[n][n].
// O(N^2)

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

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 3e3 + 5;

double dp[N][N];
double p[N];
int n;

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> p[i];

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            dp[i+1][j+1] += p[i] * dp[i][j];
            dp[i+1][j] += (1.0-p[i]) * dp[i][j];
        }
    }

    double res = 0.0;
    for(int j = n/2+1; j <= n; ++j)
        res += dp[n][j];

    cout << fixed << setprecision(10) << res << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
