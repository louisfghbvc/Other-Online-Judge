// Remember... do not use unordered_map. TLE.
// this version is clean code.

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

const int N = 2e3+5;
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully
1
4
100 100 4 100
6
1 3 2 1 4 2
8
1 2 3 3 3 2 6 6

1 3 2 1 4 2
  1 1 2 2
  groupfre
  1 2
  2 2
**/


void solve(){
    LL n;
    cin >> n;
    vi arr(n);
    cin >> arr;

    map<LL, LL> fre;
    for(LL x : arr) fre[x]++;

    map<LL, LL> groupfre;
    for(auto &[k, f]: fre) groupfre[f]++;

    LL res = n;
    int l = 0, r = n, diff = sz(fre);
    for(auto &[freK, freTime] : groupfre){
        // left drop, suffix - size * fre
        res = min(res, l + (r - diff * freK));
        l += freK * freTime;
        r -= freK * freTime;
        diff -= freTime;
    }

    cout << res << "\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}

/**
Enjoy the problem.
**/
