// Use recursive, make it simple. from small digit to big.
// also can just build pow10 array. and from big to small.

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
 
int sum(LL x){
    int res = 0;
    while(x > 0){
        res += x % 10;
        x /= 10;
    }
    return res;
}
 
LL help(LL x, LL s){
    if(sum(x) <= s) return 0;
    if(x % 10 == 0) return help(x/10, s)*10;
    return help(x+10-x%10, s) + 10-x%10;
}
 
void solve(){
    LL n, s;
    cin >> n >> s;
    cout << help(n, s) << "\n";
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
