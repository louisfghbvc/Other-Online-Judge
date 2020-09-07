// It's simple just if current sum is neg, ans + (-cur). is cur is postive. no cost.
// O(N)

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
    int n;
    cin >> n;
    vi arr(n);
    for(int i= 0; i < n; ++i) cin >> arr[i];
    LL cur = 0, res = 0;
    for(int i = 0; i < n; ++i){
        if(arr[i] < 0){
            cur += arr[i];
            if(cur < 0){
                res += -cur;
                cur = 0;
            }
        }
        else{
            cur += arr[i];
        }
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
