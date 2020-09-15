// Very Simple math, just compute how many need. cuz k times y is must, so ky. and need k sticks also.
// so need = ky+k. will 1+(x-1)a >= need. so simple. just divide.
// so shit the long long. if mul overflow. so divide.
// O(1). and ceil(a/b) = (a+b-1)/b.

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
 
void dbg_out() { cout << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
 
const int N = 2e5+5;
 
 
void solve(){
    LL x, y, k;
    cin >> x >> y >> k;
    LL res = k;
    LL need = y*k+k;
    LL a = (need-1+x-1-1)/(x-1);
    cout << res+a << "\n";
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
