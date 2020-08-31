// need a genius mind.
// think about the array length 5
// so can choose (1, 4), (1, 5). the length diff == 1 right?
// means can make (1, 4) to 0. perfect.
// finally (5,5). just length 1, so just -arr[5].
// and the length n is same idea.
// O(N)

#include <bits/stdc++.h>
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
//const int N = 2*1e5 +5;
//const int lg = 20;
//const LL mod = 1e9+7;
 
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
    if(n == 1){
        cout << "1 1" << "\n";
        cout << "0" << "\n";
        cout << "1 1" << "\n";
        cout << "0" << "\n";
        cout << "1 1" << "\n";
        cout << -arr[0] << "\n";
    }
    else{
        cout << "1 " << n-1 << "\n";
        for(int i = 0; i+1 < n; ++i){
            if(i) cout << " ";
            cout << (n-1)*arr[i];
        }
        cout << "\n";
        cout << "1 " << n << "\n";
        for(int i = 0; i+1 < n; ++i){
            if(i) cout << " ";
            cout << -n*arr[i];
        }
        cout << " 0\n";
        cout << n << " " << n << "\n";
        cout << -arr[n-1] << "\n";
    }
}
 
int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
