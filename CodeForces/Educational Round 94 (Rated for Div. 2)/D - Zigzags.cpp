// O(N^4) -> O(N^2).
// Because the monotonous. i<j<k<l, A[i]==A[k] && A[j] == A[l].
// So if we use two map to calculate left, right
// and when j >> 1, so the left must small and check if A[k] exist, and k move backwards same idea. 

#include <bits/stdc++.h>
 
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 3005;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
void solve(){
    LL n, res = 0;
    cin >> n;
    vi arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    unordered_map<int, int> left, right;
    for(int j = 0; j < n; ++j){
        right.clear();
        for(int k = n-1; k > j; --k){
            res += left[arr[k]]*right[arr[j]];
            right[arr[k]]++;
        }
        left[arr[j]]++;
    }
    cout << res << "\n";
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
