// misunderstand question. took a long time.

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

const int N = 1e2+5;

void solve(){
    int h, w;
    cin >> h >> w;
    vector<int> fre(105);
    int mn = 1e9;
    for(int i = 0; i <h ; ++i)
        for(int j= 0, x; j < w; ++j)
            cin >> x, fre[x]++, mn = min(mn, x);
    LL res = 0;
    for(int i = mn; i <= 100; ++i){
        res += fre[i]* (i-mn);
    }
    cout << res;
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
