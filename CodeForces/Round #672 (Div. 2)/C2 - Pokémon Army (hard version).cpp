// O(N+Q). The rollback. very tricky. and merge start pos in rollback.
// and not change the pos, change val.
// monotonous. tricky

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
LL arr[N];
int n, q, l, r;

void change(int ind, LL val, LL& res){
    res -= arr[0];
    if(ind) res -= max(0LL, arr[ind]-arr[ind-1]);
    if(ind+1<n) res -= max(0LL, arr[ind+1]-arr[ind]);

    arr[ind] = val;

    if(ind) res += max(0LL, arr[ind]-arr[ind-1]);
    if(ind+1<n) res += max(0LL, arr[ind+1]-arr[ind]);
    res += arr[0];
}

void solve(){
    cin >> n >> q;
    memset(arr, 0, sizeof arr);

    LL res = 0;
    for(int i = 0, x; i < n; ++i){
        cin >> x;
        change(i, x, res);
    }
    cout << res << "\n";

    while(q--){
        cin >> l >> r; l--, r--;
        LL tmp = arr[l];
        change(l, arr[r], res);
        change(r, tmp, res);
        cout << res << "\n";
    }
}

int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
