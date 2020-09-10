// Build graph, and run dp. O(NE).
// first case can ignore.
// look at second and third case. and third is same as second. just add neg.
// Stack to use for decrease array. left, right. postion because that can cover all case.
// When left smaller than cur pop it. same as right.
// So, Main idea is from current index, what is the nearest index left, and right. that value > current value.

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

const int N = 3e5 + 5;
vi jump[N];
int n;
void nearestHigh(vi &h){
    // look nearest Left.
    vector<int> st;
    for(int i = 0; i < n; i++){
        while(sz(st) && h[st.back()] < h[i]) st.pop_back();
        if(sz(st)) jump[st.back()].push_back(i);
        st.push_back(i);
    }
    st.clear();
    // look nearest Right.
    for(int i = n-1; i >= 0; --i){
        while(sz(st) && h[st.back()] < h[i]) st.pop_back();
        if(sz(st)) jump[i].push_back(st.back());
        st.push_back(i);
    }
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i) jump[i].clear();
    vi h(n); cin >> h;

    vi dp(n, n-1);
    nearestHigh(h);
    for(int i = 0; i < n; ++i) h[i] = -h[i];
    nearestHigh(h);

    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int to: jump[i]){
            dp[to] = min(dp[to], dp[i]+1);
        }
    }

    cout << dp[n-1] << "\n";
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}


