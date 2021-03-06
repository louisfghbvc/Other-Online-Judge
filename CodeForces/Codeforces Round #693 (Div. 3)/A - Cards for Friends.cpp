#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<int> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 18;
const int mod = 1e9+7;


void solve(){
    int w, h, n;
    cin >> w >> h >> n;
    LL c1 = 1, c2 = 1;
    while(w % 2 == 0){
        c1 <<= 1;
        w >>= 1;
    }
    while(h % 2 == 0){
        c2 <<= 1;
        h >>= 1;
    }
    if(c1 * c2 >= n){
        cout << "YES\n";
    }
    else cout << "NO\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
