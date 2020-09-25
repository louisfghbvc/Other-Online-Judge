// tricky dp, from odd seq, or even seq. O(N)

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

const int N = 1e5+5;

void solve(){
    int n, q;
    cin >> n >> q;
    vi arr(n);
    cin >> arr;

    vi odd(n+1), even(n+1);
    odd[0] = INT_MIN;
    for(int i = 0; i < n; ++i){
        odd[i+1] = max(odd[i], even[i]+arr[i]);
        even[i+1] = max(even[i], odd[i]-arr[i]);
    }

    cout << max(odd.back(), even.back()) << "\n";

}

int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}

// Wow, Think that a subseqence. the index can vanish choose 2.
// if ans if arr[0]-arr[2]+arr[4]
// arr[0] +(-arr[1]+arr[1]) - arr[2] +(arr[3]-arr[3]) + arr[4]
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

const int N = 1e5+5;

void solve(){
    int n, q;
    cin >> n >> q;
    vi arr(n);
    cin >> arr;

    LL res = arr[0];
    for(int i = 1; i < n; ++i)
        res += max(0LL, arr[i]-arr[i-1]);

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
