#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 5e3+5;
const int INF = 0x3f3f3f3f;
/**
Read problem statement carefully
**/

void solve(int x){
    int n;
    cin >> n;
    vi A(n), B(n);
    cin >> A >> B;

    LL ans = 0;
    for(int i = 0; i < n; ++i){
        LL cur = 0;
        for(int d = 1; ; ++d){
            int l = i - d, r = i + d;
            if(l < 0 || r >= n) break;
            cur += (A[r] - A[l]) * B[l] + (A[l] - A[r]) * B[r];
            ans = max(ans, cur);
        }
    }
    for(int i = 0; i+1 < n; ++i){
        LL cur = (A[i+1] - A[i]) * B[i] + (A[i] - A[i+1]) * B[i+1];
        ans = max(ans, cur);
        for(int d = 1; ; ++d){
            int l = i - d, r = i + 1 + d;
            if(l < 0 || r >= n) break;
            cur += (A[r] - A[l]) * B[l] + (A[l] - A[r]) * B[r];
            ans = max(ans, cur);
        }
    }

    for(int i = 0; i < n; ++i)
        ans += A[i] * B[i];
    cout << ans << "\n";
}

int main()
{
    Fast;
    // louisfghbvc
        solve(1);
    return 0;
}

/**
Enjoy the problem.
**/
