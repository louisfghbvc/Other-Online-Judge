// math, factor the number. and check.
// O(sqrt(N)).

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
/**
Read problem statement carefully
**/


void solve(){
    LL n;
    cin >> n;
    int res = 0;
    n*=2;
    for(LL x = 1; x*x <= n; ++x){
        if(n%x == 0){
            LL r = n/x;
            LL v = (x + 1 - r)/2;
            res += (v*2+r-1) == x;

            v = (r + 1 - x)/2;
            res += (v*2+x-1) == r;
        }
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
