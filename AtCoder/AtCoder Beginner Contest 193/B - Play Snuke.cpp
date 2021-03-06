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

const int N = 1e2+5;
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully
sum + len*y == x
**/



void solve(){
    int n;
    cin >> n;
    bool ok = 0;
    LL res = 1e9+5;
    for(int i = 0; i < n; ++i){
        LL a, p, k;
        cin >> a >> p >> k;
        k -= a;
        if(k > 0){
            ok = 1;
            res = min(res, p);
        }
    }
    if(!ok) cout << -1 << "\n";
    else cout << res << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}

/**
Enjoy the problem.
**/
