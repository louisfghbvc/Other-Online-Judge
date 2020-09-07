// O(N). QQ stick with the '?'
// just use two array to check the zero and one. and '?' ignore.
// and when sliding the i+1 must same as i-k. so that can be equal.
// important observe.

#include <bits/stdc++.h>
 
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
void solve(){
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    vector<bool> zero(k), one(k);
    for(int i = 0; i < n; ++i){
        if(s[i] == '0') zero[i%k] = 1;
        if(s[i] == '1') one[i%k] = 1;
    }
    bool ok = 1;
    for(int i = 0; i < k; ++i){
        if(zero[i] && one[i]) ok = 0;
    }
    int zeroCnt = 0, oneCnt = 0;
    for(int i = 0; i < k; ++i){
        if(zero[i]) zeroCnt++;
        if(one[i]) oneCnt++;
    }
    if(zeroCnt > k/2 || oneCnt > k/2) ok = 0;
    cout << (ok ? "YES": "NO") << "\n";
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
