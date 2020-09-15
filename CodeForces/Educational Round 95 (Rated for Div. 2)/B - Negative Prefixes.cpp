// O(NlogN). the main idea is make the suffix biggest. Pn is no change. and k is small. means from back longer > 0.
// Pn-1 = Pn-val, say val is smallest. so that make the suffix biggest.

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
 
void dbg_out() { cout << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
 
void solve(){
    int n;
    cin >> n;
    vi A(n);
    vi lock(n);
    cin >> A >> lock;
 
    vi unlocked;
    for(int i = 0; i < n; ++i){
        if(!lock[i]) unlocked.push_back(i);
    }
 
    vi order = unlocked;
    sort(All(order), [&](int a, int b){
        return A[a] > A[b];
    });
 
    vi B = A;
    for(int i = 0; i < sz(unlocked); ++i)
        B[unlocked[i]] = A[order[i]];
 
    for(int i = 0; i < n; ++i)
        cout << B[i] << " \n"[i==n-1];
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
