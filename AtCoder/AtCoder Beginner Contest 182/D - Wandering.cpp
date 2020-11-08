// Prefix max. and Prefix.
// Can one pass...
// O(N).

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
    vi pre(n);
    vi mxP(n);
    pre[0] = arr[0];
    mxP[0] = arr[0];
    for(int i = 1; i < n; ++i) pre[i] += pre[i-1] + arr[i];
    for(int i = 1; i < n; ++i) mxP[i] = max(mxP[i-1], pre[i]);

    LL x = 0, mx = LLONG_MIN;
    for(int i = 0; i < n; ++i){
        mx = max({x+mxP[i], mx, x});
        x += pre[i];
    }
    cout << mx << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
