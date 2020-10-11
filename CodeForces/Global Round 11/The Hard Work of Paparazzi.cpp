// LIS tweak.
// O(NR). if i > 2*r. remember to check ans[i] =  ans[i] or max_ans[i-2*r]+1. why? cuz we have not update the over range > 2*r ans[j].
// and since i is big so j is from i-2*r or 0.

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<int> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }


const int N = 1e5+5;
int t[N], x[N], y[N];
int ans[N], mx_ans[N];

void solve(){
    int r, n;
    cin >> r >> n;

    x[0] = 1, y[0] = 1;
    for(int i = 1; i <= n; ++i)
        cin >> t[i] >> x[i] >> y[i];

    for(int i = 1; i <= n; ++i){
        ans[i] = -1e9;
        for(int j = max(i-2*r, 0); j < i; j++){
            int d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            if(d <= t[i]-t[j]){
                ans[i] = max(ans[i], ans[j]+1);
            }
        }
        if(i > 2*r) ans[i] = max(ans[i], mx_ans[i-2*r]+1);
        mx_ans[i] = max(ans[i], mx_ans[i-1]);
    }

    cout << mx_ans[n] << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
