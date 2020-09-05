// first enum minimum d. because the difference.
// and just build the remain array.

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
    LL n, x, y;
    cin >> n >> x >> y;
    if(n == 2){
        cout << x << " " << y << "\n";
        return;
    }
    LL d = -1;
    for(int i = n-1; i >= 1; --i){
        if((y-x)%i == 0){
            d = (y-x)/i; break;
        }
    }
    vi arr;
    for(int i = x; i <= y; i += d) arr.push_back(i);
    int sz = arr.size();
    if(sz < n){
        for(int i = x-d; i > 0; i -= d) arr.push_back(i);
    }
    for(int i = y+d; arr.size() < n; i += d) arr.push_back(i);
    for(int i = 0; i < n; ++i) cout << arr[i] << " \n"[i==n-1];
}
 
int main()
{
 
    Fast;
    louisfghbvc{
        solve();
    }
 
    return 0;
}
