// Just DJS. find largest group, so that just cut that group.
// O(N). can optimal. but it's ok.

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
int p[N];
 
int find(int x){
    return p[x] < 0 ? x : p[x] = find(p[x]);
}
 
void solve(){
    int n, m, a, b;
    cin >> n >> m;
    memset(p, -1, sizeof p);
 
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if(pa != pb){
            p[pa] += p[pb];
            p[pb] = pa;
        }
    }
 
    int mx = 0;
    for(int i = 1; i <= n; ++i){
        mx = max(mx, -p[find(i)]);
    }
    cout << mx << "\n";
}
 
int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
