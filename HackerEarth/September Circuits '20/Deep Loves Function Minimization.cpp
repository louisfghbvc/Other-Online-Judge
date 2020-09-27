// OMG... just greedy...
// So the pos choose * rest must be smallest.

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

const int mod = 1e9+7;
const int N = 1e5+5;
LL A[5][N];

bool com1(ii &a, ii &b){
    return a.first * b.second < b.first * a.second;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= 3; ++i) 
        for(int j = 1; j <= n; j++)
            cin >> A[i][j];
    for(int j = 1; j <= n; ++j)
        A[2][j] *= A[3][j];

    vector<ii> arr(n);
    for(int i = 0; i < n; ++i)
        arr[i] = {A[1][i+1], A[2][i+1]};
    sort(All(arr), com1);

    vi suf(n);
    suf[n-1] = arr[n-1].second;
    for(int i = n-2; i >= 0; --i)
        suf[i] = (suf[i+1]+arr[i].second)%mod;

    LL res = 0;
    for(int i = 1; i < n; ++i){
        res += (arr[i-1].first*suf[i]) % mod;
        res %= mod;
    }
    cout << res << "\n";
}

int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
