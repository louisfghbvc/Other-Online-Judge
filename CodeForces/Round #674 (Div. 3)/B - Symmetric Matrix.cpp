// just simple to observe that the 2x2 is symmetric must (0,1) = (1,0).
// and I confused the test case 1x1. out YES. so that fail...
// just misunderstand the testcase... shxt QAQ

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
 
const int N = 3e5+5;
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    int arr[n+2][4][4];
    memset(arr, 0, sizeof arr);
 
    bool has = false;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 2; ++k)
                cin >> arr[i][j][k];
        if(arr[i][0][1] == arr[i][1][0]) has = 1;
    }
 
    if(m % 2){
        cout << "NO\n";
        return;
    }
    cout << (has ? "YES" : "NO") << "\n";
}
 
int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
