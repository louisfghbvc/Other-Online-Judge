// Very nice problem.
// O(NlogN) sort first, and two pointer calculate the max prefix and suffix array.
// current point x,  l[i] means max diff smaller than k points have. same as r[i].
// and sliding maintain max.

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
    LL n, k;
    cin >> n >> k;
    vi x(n), y(n);
    for(auto &it: x) cin >> it;
    for(auto &it: y) cin >> it;
    sort(All(x));
    vi l(n), r(n);
    int j = 0;
    for(int i = 0; i < n; ++i){
        while(x[i] - x[j] > k) j++;
        l[i] = i-j+1;
        if(i) l[i] = max(l[i], l[i-1]);
    }
    j = n-1;
    for(int i = n-1; i >= 0; --i){
        while(x[j] - x[i] > k) j--;
        r[i] = j-i+1;
        if(i+1 < n) r[i] = max(r[i], r[i+1]);
    }
    LL mx = 1;
    for(int i = 0; i+1 < n; ++i){
        mx = max(mx, l[i] + r[i+1]);
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
