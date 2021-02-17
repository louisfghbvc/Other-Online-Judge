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

const int N = sqrt(1e12+5);
const int mod = 1e9+7;
/**
Read problem statement carefully
a^3 + b^3 = x
**/

void solve(){
    LL x;
    cin >> x;
    for(LL a = 1; a*a*a < x; ++a){
        LL b = cbrt(x - a*a*a);
        if(a*a*a + b*b*b == x){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

void init(){
}

int main()
{
    Fast;
    init();
    louisfghbvc
        solve();
    return 0;
}

/**
enjoy the problem.
**/
