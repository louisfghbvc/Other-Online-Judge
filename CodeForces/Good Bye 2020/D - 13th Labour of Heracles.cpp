// Greedy. Tree O(NlogN). Almost...
// So just add color to each deg > 1 node. sorted from big to small.

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

const int mod = 1e9+7;
const int N = 1e5+5;

int in[N];

void solve(){
    int n;
    cin >> n;
    memset(in, 0, sizeof in);

    vi w(n);
    cin >> w;

    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        in[u]++, in[v]++;
    }

    vi can;
    LL tot = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 1; j < in[i]; ++j) can.push_back(w[i]);
        tot += w[i];
    }

    sort(can.rbegin(), can.rend());
    cout << tot;
    for(auto&v: can){
        tot += v;
        cout << " " << tot;
    }
    cout << "\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
