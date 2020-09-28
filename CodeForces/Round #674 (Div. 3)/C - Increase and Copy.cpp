// Enum all case. from 1 to sqrt(N). just like factor. the more value, copy fast.
// so enum all val. and why not value could be fusion? autally is fusion. because ceil.
// think case about 3. 1,1,1. and 2,1. and 3. enum n?
// think 4. 1 3, 2 2, 4.
// think 8. 1 7, 2 2 2 2, 3 3 2, 4 4... 
// well... make sense? the greedy is max add value. but also small cost.
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
 
void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
const int N = 2e5+5;
 
void solve(){
    int n;
    cin >> n;
    LL res = n;
    for(LL i = 1; i*i <= n; ++i){
        LL addC = i-1;
        LL copyC = (n-i+(i-1))/i;
        res = min(res, addC + copyC);
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
