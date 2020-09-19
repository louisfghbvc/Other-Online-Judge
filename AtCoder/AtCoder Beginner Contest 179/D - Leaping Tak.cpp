// Dp of dp, dp + prefix dp.
// O(Nk). think about if range a interval (1, 3). so dp[i] can from dp[i-3] + .... dp[i-1]. just prefix the dp. 

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
 
const int N = 2e5+5;
const int mod = 998244353;
 
int dp[N];
int sum[N];
 
LL get(int l, int r){
    if(l <= 1) l = 1;
    if(l > r) return 0;
    return ((sum[r] - sum[l-1])%mod + mod)%mod;
}
 
void solve(){
    int n, k;
    cin >> n >> k;
 
    vi L(k), R(k);
    vi st;
    for(int i = 0; i < k; ++i){
        cin >> L[i] >> R[i];
    }
 
    dp[1] = 1;
    sum[1] = 1;
    for(int i = 2; i <= n; ++i){
        for(int j = 0; j < k; ++j){
            dp[i] = (dp[i] + get(i-R[j], i-L[j])) % mod;
        }
        sum[i] = (sum[i-1] + dp[i])%mod;
    }
 
    cout << dp[n] << "\n";
}
 
int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
