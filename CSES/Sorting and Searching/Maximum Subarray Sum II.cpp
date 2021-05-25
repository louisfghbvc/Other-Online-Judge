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

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
/**
Read problem statement carefully
8 1 1
-1 3 -2 5 3 -5 2 2
**/


void solve(int T){
    int n, a, b;
    cin >> n >> a >> b;

    vi arr(n);
    cin >> arr;

    vi pre(n);
    pre[0] = arr[0];
    for(int i = 1; i < n; ++i) pre[i] += pre[i-1] + arr[i];

    multiset<LL> st;
    st.insert(0);
    
    LL res = pre[a-1];
    bool flag = false;
    for(int i = a; i < n; ++i){
        if(i >= b){
            if(!flag){
                flag = 1;
                st.erase(st.find(0));
            }
        }
        if(i >= a) st.insert(pre[i-a]);
        res = max(res, pre[i] - *st.begin());
        if(i >= b){
            st.erase(st.find(pre[i-b]));
        }
    }
    cout << res << "\n";
}

int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}

/**
Enjoy the problem.
**/
