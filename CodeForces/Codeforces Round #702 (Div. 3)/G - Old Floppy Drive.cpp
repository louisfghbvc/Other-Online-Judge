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

const int N = 2e5+5;
const int mod = 1e9+7;
/**
Read problem statement carefully
1
4
1 2 4 3
5
1 1 1 1 1

**/

void solve(){
    int n, m;
    cin >> n >> m;
    vi arr(n);
    cin >> arr;

    vi pre(n);
    pre[0] = arr[0];
    for(int i = 1; i < n; ++i) pre[i] = pre[i-1] + arr[i];
    LL tot = pre.back();
    for(int i = 0; i+1 < n; ++i){
        if(pre[i] > pre[i+1])
            pre[i+1] = pre[i];
    }

    LL x;
    while(m--){
        cin >> x;
        if(pre.back() >= x){
            cout << lower_bound(All(pre), x) - pre.begin() << " ";
        }
        else if(tot <= 0){
            cout << "-1 ";
        }
        else{
            LL y = x - pre.back();
            LL turn = (y + tot - 1) / tot;
            cout << turn * n + (lower_bound(All(pre), x - turn * tot) - pre.begin()) << " ";
        }
    }
    cout << "\n";
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
