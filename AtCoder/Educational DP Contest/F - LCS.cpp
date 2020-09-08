// LCS print.
// remember the tracking is back to begin.
// and RE check, i>0 && j>0 not or. because dp is from i=1, j=1.
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

const int N = 3e3+5;
int dp[N][N];
int dir[N][N];

void solve(){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();


    memset(dp, 0, sizeof dp);
    memset(dir, 0, sizeof dir);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                dir[i][j] = 1;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    dir[i][j] = 2;
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dir[i][j] = 3;
                    dp[i][j] = dp[i][j-1];
                }
            }


    string res = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(dir[i][j] == 1){
            res += s[i-1];
            i--; j--;
        }
        else if(dir[i][j] == 2) i--;
        else j--;
    }
    reverse(All(res));
    cout << res << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
