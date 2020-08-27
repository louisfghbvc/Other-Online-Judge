// Nice D&C
// so first find mid. and mid index. like leetcode problem.
// O(N^2). Can also use segment tree to record the min index. so fast the query to O(logN).

#include <bits/stdc++.h>
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 5005;
LL arr[N];

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

LL help(int l, int r){
    if(l > r) return 0;
    int mn = INT_MAX, mn_ind = -1;
    for(int i = l; i <= r; ++i){
        if(mn > arr[i]){
            mn = arr[i];
            mn_ind = i;
        }
    }
    for(int i = l; i <= r; ++i) arr[i] -= mn;
    return min((LL)r-l+1, help(l, mn_ind-1) + help(mn_ind+1, r) + mn);
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    cout << help(0, n-1) << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
