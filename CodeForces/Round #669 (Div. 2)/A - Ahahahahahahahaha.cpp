// Just Enum. count the zero and one frequency.
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
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
void solve(){
    int n;
    cin >> n;
    vi arr(n);
    for(auto &it: arr) cin >> it;
 
    int one = 0, zo = 0;
    for(int x: arr)
        if(x) one++;
        else zo++;
 
    for(int i = n/2; i >= 0; --i){
        int re = n-i;
        if(re % 2 == 0){
            if(one >= re){
                cout << re << "\n";
                for(int k = 0; k < re; ++k)
                    cout << 1 << " \n"[k==re-1];
                return;
            }
        }
        else{
            if(zo >= re){
                cout << re << "\n";
                for(int k = 0; k < re; ++k)
                    cout << 0 << " \n"[k==re-1];
                return;
            }
        }
    }
 
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
