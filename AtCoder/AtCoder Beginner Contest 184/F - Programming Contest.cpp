// Cool divide O(2^40) to 2^20.
// So Enum first part. and second part Enum remain. and combine. check max.

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
const int N = 45;
const int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
LL arr[N];
set<LL> st;

void solve(){
    LL n, t;
    cin >> n >> t;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    st.insert(0);
    int x = n/2;
    for(int i = 0; i < (1<<x); ++i){
        LL res = 0;
        for(int j = 0; j < x; ++j){
            if(i&(1<<j)) res += arr[j];
        }
        if(res <= t) st.insert(res);
    }

    int x2 = n-x;
    LL mx = 0;
    for(int i = 0; i < (1<<x2); ++i){
        LL res = 0;
        for(int j = 0; j < x2; ++j){
            if(i&(1<<j)) res += arr[x+j];
        }
        if(res > t) continue;
        auto it = prev(st.upper_bound(t - res));
        mx = max(mx, *it + res);
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
