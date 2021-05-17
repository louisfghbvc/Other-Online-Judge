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

const int N = 2e3+5;
const int INF = 0x3f3f3f3f;
/**
Read problem statement carefully
**/

int hh = 0;
int dp[1<<11];
LL dfs(string &s, int k, int vis){
    if(k == 4){
        if((hh & vis) == hh){
            // cout << tmp << "\n";
            return 1;
        }
        return 0;
    }
    // if(dp[vis] != -1) return dp[vis];
    LL res = 0;
    for(int i = 0; i < 10; ++i){
        if(s[i] == 'o')
            res += dfs(s, k+1, vis | (1<<i));
        else if(s[i] == '?')
            res += dfs(s, k+1, vis | (1<<i));
    }
    return dp[vis] = res;
}

void solve(int n){
    memset(dp, -1, sizeof dp);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == 'o')
            hh |= (1<<i);
    }
    // cout << bitset<10>(hh) << "\n";
    cout << dfs(s, 0, 0) << "\n";
}

int main()
{
    // Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    
    return 0;

}

/**
Enjoy the problem.
**/
