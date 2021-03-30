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

const int N = 305;
const int INF = 0x3f3f3f3f;
/**
Read problem statement carefully
4
1 1
2 2
**/

void solve(){
    int n;
    cin >> n;
    vi L(n+1, INF);
    vi R(n+1, -INF);

    for(int i = 0; i < n; ++i){
        LL x, lb;
        cin >> x >> lb;
        L[lb] = min(L[lb], x);
        R[lb] = max(R[lb], x);
    }

    L[0] = R[0] = 0;
    LL dp[n+1][2] = {}; // 0 is final in left, 1 right
    for(int i = 1; i <= n; ++i){
        dp[i][0] = dp[i-1][0], dp[i][1] = dp[i-1][1];
        if(L[i] == INF){
            L[i] = L[i-1];
            R[i] = R[i-1];
            continue;
        }
        dp[i][0] = min(
                    dp[i-1][0] + abs(R[i]-L[i-1]) + R[i] - L[i],
                    dp[i-1][1] + abs(R[i]-R[i-1]) + R[i] - L[i]
                    );
        dp[i][1] = min(
                    dp[i-1][0] + abs(L[i]-L[i-1]) + R[i] - L[i],
                    dp[i-1][1] + abs(L[i]-R[i-1]) + R[i] - L[i]
                    );
    }

    cout << min(dp[n][0] + abs(L[n]), dp[n][1] + abs(R[n])) << "\n";


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
