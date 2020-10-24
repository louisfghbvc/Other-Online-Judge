// Just enum all num, becuase log is small.
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

const int N = 1e3+5;

LL fpow(LL x, LL y){
    LL res = 1;
    while(y){
        if(y&1) res *= x;
        x = x*x;
        y >>= 1;
    }
    return res;
}

void solve(){
    LL n;
    cin >> n;
    for(int a = 1; fpow(3, a) < n; ++a){
        LL tb = (n-fpow(3, a));
        for(int b = 1; fpow(5, b) <= tb; ++b){
            if(fpow(3, a) + fpow(5, b) == n){
                cout << a << " " << b << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
