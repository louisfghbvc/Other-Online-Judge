// So just use two prefix map. O(N).

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
 
const int N = 1e5+5;
bool color[N];
 
void solve(){
    int n, t;
    cin >> n >> t;
 
    vi arr(n); cin >> arr;
 
    unordered_map<LL, int> c;
    unordered_map<LL, int> d;
    memset(color, 0, sizeof color);
    for(int i = 0; i < n; ++i){
        if(c[t-arr[i]] > d[t-arr[i]]){
            color[i] = 1;
            d[arr[i]]++;
        }
        else c[arr[i]]++, color[i] = 0;
 
    }
    for(int i = 0; i < n; ++i)
        cout << color[i] << " \n"[i==n-1];
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
