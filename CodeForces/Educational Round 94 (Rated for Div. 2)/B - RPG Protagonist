// Math.
// If fix one value, can take all other value.
// and remember the O(N) can pass. also t = 1e4, the important is total sum < 2*10^5

#include <bits/stdc++.h>
 
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
//const int N = 2*1e5 +5;
//const int lg = 20;
//const LL mod = 1e9+7;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
void solve(){
    LL p, f, cs, cw, s, w;
    cin >> p >> f >> cs >> cw >> s >> w;
    if(s > w) swap(s, w), swap(cs, cw);
    LL a_cantake = min(cs, p/s);
    LL mx = 0;
    for(LL s1 = 0; s1 <= a_cantake; ++s1){
        LL w1 = min(cw, (p-s1*s)/w);
        LL s2 = min(cs-s1, f/s);
        LL w2 = min(cw-w1, (f-s2*s)/w);
        mx = max(mx, s1+w1+s2+w2);
    }
    cout << mx << "\n";
}
 
int main()
{
 
    Fast;
    louisfghbvc{
        solve();
    }
 
    return 0;
}
