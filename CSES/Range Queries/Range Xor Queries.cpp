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
 
const int N = 1e2+5;
const LL INF = 1e9;
const int mod = 1e9+7;
const LL MXP = 1e10;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
/**
**/

struct segmentTree {
    vi tre, arr;
    int n;
    segmentTree(int _n, vi &arr) : n(_n), arr(arr) {
        int size = 1;
        while (size < n) size <<= 1;
        tre.assign(2 * size, 0);
        build(0, 0, n-1);
    }
    void build(int id, int l, int r) {
        if (l == r) {
            tre[id] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(id*2+1, l, mid);
        build(id*2+2, mid+1, r);
        tre[id] = tre[id*2+1] ^ tre[id*2+2];
    }
    LL query(int id, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) return tre[id];
        if (l > rr || r < ll) return 0;
        int mid = (l+r)/2;
        return query(id*2+1, l, mid, ll, rr) ^ query(id*2+2, mid+1, r, ll, rr);
    }
    LL query(int l, int r) {
        return query(0, 0, n-1, l, r);
    }
};


void solve(int T) {
    // cout << "Case #" << T+1 << ": ";
    int n, q;
    cin >> n >> q;
    vi arr(n);
    cin >> arr;
    segmentTree tree(n, arr);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << tree.query(l, r) << "\n";
    }
}                                   

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
