#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 5e2+5;
const int INF = 0x3f3f3f3f;
/**
Read problem statement carefully
**/
int dp[N][N];
LL A[N][N], B[N][N];

int r, c;
void solve(int x){
    memset(dp, 0x3f, sizeof dp);
    
    cin >> r >> c;
    for(int i = 1; i <= r; ++i)
        for(int j= 1; j < c; ++j)
            cin >> A[i][j];
    
    for(int i = 1; i < r; ++i)
        for(int j = 1; j <= c; ++j)
            cin >> B[i][j];

    dp[1][1] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 0});

    while(sz(pq)){
        auto [cost, idx] = pq.top(); pq.pop();
        int x = idx/c, y = idx%c;
        x++, y++;
        if(cost > dp[x][y]) continue;
        dp[x][y] = cost;
        if(y < c){
            if(dp[x][y+1] > dp[x][y] + A[x][y]){
                dp[x][y+1] = dp[x][y] + A[x][y];
                pq.push({dp[x][y+1], (x-1) * c + y});
            }
        }
        if(y > 1){
            if(dp[x][y-1] > dp[x][y] + A[x][y-1]){
                dp[x][y-1] = dp[x][y] + A[x][y-1];
                pq.push({dp[x][y-1], (x-1) * c + y - 2});
            }
        }
        if(x < r){
            if(dp[x+1][y] > dp[x][y] + B[x][y]){
                dp[x+1][y] = dp[x][y] + B[x][y];
                pq.push({dp[x+1][y], x * c + y - 1});
            }
        }
        for(int i = 1; i < r && x - i > 0; ++i){
            int ga = 1 + i;
            if(dp[x][y] + ga < dp[x-i][y]){
                dp[x-i][y] = dp[x][y] + ga;
                pq.push({dp[x-i][y], (x - i - 1) * c + y-1}); 
            }
        }
    }

    cout << dp[r][c] << "\n";
}

int main()
{
    // Fast;
    // louisfghbvc
        solve(1);
    return 0;
}

/**
Enjoy the problem.
**/
