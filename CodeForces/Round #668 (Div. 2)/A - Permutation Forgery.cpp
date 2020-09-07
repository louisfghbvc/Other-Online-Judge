// Simple to observe just reverse, so that the relative array add will not change.
// O(N). waste 10 mins to figure out just reverse...

#include <bits/stdc++.h>
 
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n ; ++i) cin >> arr[i];
    reverse(arr.begin(), arr.end());
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
