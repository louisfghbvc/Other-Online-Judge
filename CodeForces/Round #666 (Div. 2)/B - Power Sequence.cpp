// so just to determine the c.
// and observe that the upperbound of c can be small. QQ WA on main test because of upperbound set too small
// how to choose upperbound? I choose it = pow(1e14, 1/n)
// 1e14 is total array all max, sum
// after that enum the c and calculate the total difference.
// O(Nsqrt(1e14))~O(N)

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
 
const int N = 1e5+5;
LL arr[N];
 
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr+n);
    LL r = pow(1e14, (double)1/n);
    //dbg_out(r);
    LL mn = LLONG_MAX;
    for(int i = 1; i <= r; ++i){
        LL d = 0;
        LL seq = 1;
        for(int k = 0; k < n; ++k){
            d += abs(arr[k]-seq);
            seq *= i;
        }
        if(d < mn) mn = d;
    }
    cout << mn << "\n";
}
 
int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
