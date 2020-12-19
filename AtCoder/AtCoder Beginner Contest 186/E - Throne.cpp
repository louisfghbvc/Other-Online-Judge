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

LL ex_gcd(LL a, LL b, LL& x, LL& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL d = ex_gcd(b, a % b, x, y);
    LL temp = x;
    x = y;
    y = temp - a / b * y;
    return d;
}

LL mod_inv(LL a, LL m){
    LL x, y;
    ex_gcd(a, m, x, y);
    return x;
}

void solve(){
    LL n, s, k;
    cin >> n >> s >> k;

    // s + k*x = 0 (mod n)
    s = n-s;
    LL g = __gcd(k, n);
    if(s % g){
        cout << -1 << "\n";
        return;
    }
    k /= g, n /= g, s /= g;
    LL k_inv = mod_inv(k, n);
    cout << (s * k_inv % n + n) % n << "\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
