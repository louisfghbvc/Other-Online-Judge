// Cool, Formula. Math bit.
// where f(x, c) means (x & 2^c) bit is 1 or 0
// x & y = enum all c of 2^c * f(x, c) * f(y, c)
// x | y = enum all c of 2^c * ( 1 - (1 - f(x, c)) * (1 - f(y, c)) )
// ∑(x&y)=∑c=0M2c∑if(xi,c)⋅f(xj,c)
// O(NP).

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

const int N = 5e5+5;
const int P = 60;
const int mod = 1e9+7;
LL arr[N];
int cnt[P];

void solve(){
    int n;
    cin >> n;
    memset(cnt, 0, sizeof cnt);

    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        for(int j = 0; j < P; ++j)
            cnt[j] += arr[i] >> j & 1;
    }

    LL ans = 0;
    for(int i = 0; i < n; ++i){
        LL sum_or = 0, sum_and = 0;
        for(int c = 0; c < P; ++c){
            if(arr[i] >> c & 1LL){
                sum_and += (1LL << c) % mod * cnt[c];
                sum_or += (1LL << c) % mod * n;
            }
            else{
                sum_or += (1LL << c) % mod * cnt[c];
            }
        }
        sum_and %= mod, sum_or %= mod;
        ans = (ans + sum_and * sum_or) % mod;
    }

    cout << ans << "\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
