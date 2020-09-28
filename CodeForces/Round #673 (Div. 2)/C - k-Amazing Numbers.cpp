// Tricky, use two pointer concept to determine maximum window size. 
// Think about small case, and think bigger. first think arr.size == 3.
// what can determine length k val.
// O(N).

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
 
const int N = 3e5+5;
int arr[N];
 
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> pos(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        --arr[i];
        pos[arr[i]].push_back(i);
    }
 
    vector<int> res(n+2, n+n);
    for(int i = 0; i < n; ++i){
        int start = -1, mx = 0;
        for(int j: pos[i]){
            mx = max(mx, j-start);
            start = j;
        }
        mx = max(mx, n-start);
        res[mx] = min(res[mx], i);
    }
 
    int mn = n+n;
    for(int k = 1; k <= n; ++k){
        mn = min(mn, res[k]);
        cout << (mn > n ? -1 : mn+1) << " \n"[k==n];
    }
 
}
 
int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
