// Math. abs lemma |a| + |b| => max(|a+b|, |a-b|);
// proof |a|+|b| = max( (1)a+b, (2)a-b, (3)-a+b, (4)-a-b ) => (1)(4) merge, (2)(3) merge => max(|a+b|, |a-b|)

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

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 2e5+5;
const int mod = 1e9+7;

void solve(){
    int n, x, y;
    cin >> n;
    vi diff[2];
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        diff[0].push_back(x+y);
        diff[1].push_back(x-y);
    }
    for(int i = 0; i < 2; ++i)
        sort(All(diff[i]));
    cout << max(diff[0].back()-diff[0][0], diff[1].back()-diff[1][0]) << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
