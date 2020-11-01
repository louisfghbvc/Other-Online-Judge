// Enum all position.
// use dp pre+suf. diff array.
// just like remove i. connected to w.
// remain sum. not intuition

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

const int mod = 1e9+7;
const int N = 2e3+5;

void solve(){
    int n, m;
    cin >> n >> m;
    vi h(n); cin >> h;
    vi w(m); cin >> w;

    sort(All(h));
    sort(All(w));

    vi dp(n);
    LL res = LLONG_MAX;

    dp[0] = -h[0];
    for(int i = 1; i < n; ++i){
        dp[i] = dp[i-1];
        if(i%2) dp[i] += h[i];
        else dp[i] -= h[i];
    }

    for(int i = 0; i < n; ++i){
        LL sum = 0;
        if(i) sum += dp[i-1];
        sum -= (dp[n-1] - dp[i]);
        auto pos = lower_bound(All(w),h[i]);
        LL t = 1e15;
        if(pos != w.end()){
            t = *pos - h[i];
        }
        if(pos != w.begin()){
            t = min(h[i]-*prev(pos), t);
        }
        sum += t;
        res = min(res, sum);
    }

    cout << res << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
