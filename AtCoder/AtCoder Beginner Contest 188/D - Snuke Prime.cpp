// Confused in problem statement.
// line sweep and euler tour. greedy. 
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

const int N = 3e5+5;
const int mod = 1e9+7;

void solve(){
    LL n, co;
    cin >> n >> co;

    vector<ii> arr(n);
    for(int i = 0; i < n; ++i){
        LL l, r, c;
        cin >> l >> r >> c;
        arr.push_back({l, c});
        arr.push_back({r+1, -c});
    }
    sort(All(arr));

    LL now = 0;
    LL res = 0;
    for(int i = 0; i+1 < sz(arr); ++i){
        now += arr[i].second;
        res += min(now, co) * (arr[i+1].first-arr[i].first);
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

/**
enjoy the problem.
**/
