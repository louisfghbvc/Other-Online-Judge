// sad... important port is tmp is always set inf.
// cuz must use value.
// each can be + or -.
// top-down. so that final just check dp[sum].
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

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 2e5+5;

void solve(){
    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;

    int tot = 0;
    for(int x: arr) tot += abs(x);
    if(tot&1){
        cout << -1 << "\n";
        return;
    }
    tot *= 2;
    vector<int> dp(tot+1, 1e5);
    dp[tot/2] = 0;
    for(int i = 0; i < n; ++i){
        vector<int> tmp(tot+1, 1e5);
        for(int j = 0; j <= tot; ++j){
            if(j - idx >= 0){
                int cost = (arr[i] < 0);
                tmp[j] = min(tmp[j], dp[j-idx]+cost);
            }
            if(j + idx <= tot){
                int cost = (arr[i] > 0);
                tmp[j] = min(tmp[j], dp[j+idx]+cost);
            }
        }
        dp = tmp;
    }
    cout << ((dp[tot/2] == 1e5) ? -1 : dp[tot/2]) << "\n";
}
int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
