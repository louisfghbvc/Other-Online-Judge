// Why is compare 2*a - b? Almost done.QQ
// Because if choose. A lose a, B gain a+b. u want to minimum A, maximum B. at the same time
// 4 1
// 1 5
// 2 2
// if only sort a+b. u get 2.
// but 2*a+b. only 1.

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

void solve(){
    int n;
    cin >> n;
    vi A(n), B(n);

    LL sum = 0;
    vector<array<LL, 2>> arr(n);

    for(int i = 0; i < n; ++i){
        cin >> A[i] >> B[i];
        sum += A[i];
        arr[i] = { 2*A[i] + B[i], A[i]};
    }

    sort(All(arr), [&](array<LL, 2> &a, array<LL, 2> &b){
            return a[0] > b[0];
        });

    LL cnt = 0, bob = 0;
    while(sum >= bob){
        sum -= arr[cnt][1];
        bob += arr[cnt][0] - arr[cnt][1];
        cnt++;
    }
    cout << cnt << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
