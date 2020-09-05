// 2 case.

#include <bits/stdc++.h>
 
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
 
void solve(){
    LL a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    LL res = LLONG_MAX;
    LL ta = a, tb = b, tn = n;
    if(a-x >= n){
        a -= n;
    }
    else{
        LL d = a-x;
        n -= d;
        a = x;
        if(b-y >= n){
            b -= n;
        }
        else b = y;
    }
    res = min(a*b, res);
    a = ta, b = tb, n = tn;
    if(b-y >= n){
        b -= n;
    }
    else{
        LL d = b-y;
        n -= d;
        b = y;
        if(a-x >= n){
            a -= n;
        }
        else a = x;
    }
    res = min(a*b, res);
    cout << res << "\n";
}
 
int main()
{
 
    Fast;
    louisfghbvc{
        solve();
    }
 
    return 0;
}
