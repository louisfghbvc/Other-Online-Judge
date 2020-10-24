// can observe that. decrease > increase.
// so m < 0 impossible.
// m = 0, always possible.
// all number unique. shit WA... edge case. if n = 1, m = 0.
// m >= n-1 impossble, can't gen n-1.
// but can gen all diff n-2~0.
// let first so big. so that increase must choice.
// make continue segment are all small and not intersect. and inc can not choose cuz end point too big.
// continue seg = m+1. observe.
// remain is n-con-1.

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
    LL n, m;
    cin >> n >> m;
    if(m == 0){
        for(LL i = 0; i < n; ++i)
            cout << i*2+1 << " " << i*2+2 << "\n";
        return;
    }
    if(m < 0 || m >= n-1){
        puts("-1");
        return;
    }

    LL con = 1+m;
    LL re = n-con-1;
    LL st = 1, ed = 2*n;
    cout << st << " " << ed << "\n";
    for(LL i = 0; i < con; ++i)
        cout << st+i*2+1 << " " << st+i*2+2 << "\n";
    for(LL i = 0; i < re; ++i)
        cout << ed+i*2+1 << " " << ed+i*2+2 << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
