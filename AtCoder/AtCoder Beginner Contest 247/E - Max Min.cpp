/**                                          
 __         ______     __  __     __     ______     ______   ______     __  __     ______     __   __   ______    
/\ \       /\  __ \   /\ \/\ \   /\ \   /\  ___\   /\  ___\ /\  ___\   /\ \_\ \   /\  == \   /\ \ / /  /\  ___\   
\ \ \____  \ \ \/\ \  \ \ \_\ \  \ \ \  \ \___  \  \ \  __\ \ \ \__ \  \ \  __ \  \ \  __<   \ \ \'/   \ \ \____  
 \ \_____\  \ \_____\  \ \_____\  \ \_\  \/\_____\  \ \_\    \ \_____\  \ \_\ \_\  \ \_____\  \ \__|    \ \_____\ 
  \/_____/   \/_____/   \/_____/   \/_/   \/_____/   \/_/     \/_____/   \/_/\/_/   \/_____/   \/_/      \/_____/                                       
**/
#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(All(x)); x.erase(unique(All(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/
 
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }
 
const int N = 1e5+5;
const LL INF = 1e13;
const int mod = 998244353;
const LL MXP = 1e10;
/**
**/


// arr that value is in [y, x]
int n, x, y;
LL helper(vi& arr) {
    LL res = 0;
    multiset<LL> st;
    for (int r = 0, l = 0; r < arr.size(); ++r) {
        st.insert(arr[r]);
        while (st.size() && *st.rbegin() == x && *st.begin() == y) {
            res += arr.size() - r;
            st.erase(st.find(arr[l]));
            l++;
        }
    }
    return res;
}

void solve(int T) {
    cin >> n >> x >> y;

    vi arr(n);
    cin >> arr;

    // goal: find the number of pairs (l,r)
    // min of them is y, max of them is x

    // idea: two pointers
    // subwindow is satisfied 
    // for each segment, calculate the sliding window numbers

    LL ans = 0;
    for (int i = 0, j; i < n; i = j) {
        vi tmp;
        j = i;
        while (j < n && arr[j] <= x && arr[j] >= y) {
            tmp.push_back(arr[j]);
            j++;
        }
        ans += helper(tmp);
        if (i == j) j++;
    }

    cout << ans << '\n';
}   

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
