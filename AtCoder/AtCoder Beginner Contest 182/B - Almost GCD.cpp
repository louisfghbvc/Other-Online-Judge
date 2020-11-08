// check all number [2, 1000]. cuz val is small
// Record max.

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

const int N = 2e5+5;

void solve(){
    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;
    int mx = 0, mxi = 2;
    for(int i = 2; i <= 1000; ++i){
        int cnt = 0;
        for(int x: arr){
            if(x%i == 0) cnt++;
        }
        if(cnt > mx){
            mx = cnt;
            mxi = i;
        }
    }
    cout << mxi << "\n";
}
int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}


