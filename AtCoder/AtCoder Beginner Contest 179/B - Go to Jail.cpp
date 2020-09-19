// 
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
 
void solve(){
    int n;
    cin >> n;
    int arr[n][2];
    for(int i = 0; i < n; ++i){
        cin >> arr[i][0] >> arr[i][1];
    }
 
    bool ex = 0;
    for(int i = 0; i+2 < n; ++i){
        if(arr[i][0] == arr[i][1] && arr[i+1][0] == arr[i+1][1] && arr[i+2][0] == arr[i+2][1]) ex = 1;
    }
 
    puts(ex ? "Yes" : "No");
}
 
int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
