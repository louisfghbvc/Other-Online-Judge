// O(N^2).

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
    int n;
    cin >> n;
    vi arr(n);
    for(auto &it: arr) cin >> it;
 
    sort(arr.rbegin(), arr.rend());
    int g = arr[0];
    cout << g;
    swap(arr[0], arr.back());
    arr.pop_back();
    while(arr.size()){
        int mxi = 0, mx = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(__gcd(g, (int)arr[i]) > mx){
                mxi = i;
                mx = __gcd(g, (int)arr[i]);
            }
        }
        g = mx;
        cout << " " << arr[mxi];
        swap(arr[mxi], arr.back());
        arr.pop_back();
    }
    cout << "\n";
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
