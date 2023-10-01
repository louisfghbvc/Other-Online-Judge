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
 
const int N = 5e5+5;
const LL INF = 1e13;
const int mod = 998244353;
const LL MXP = 998244353;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);

/**
**/

struct node {
    int ans[2] = {};
    int pre[2] = {};
    int suf[2] = {}; 
    int tag=0;
    int len=0;
    node() {}
    node(char c) {
        ans[c-'0'] = 1;
        pre[c-'0'] = 1;
        suf[c-'0'] = 1;
        len = 1;
    }
};
node seg[4*N];

void apply(int id) {
    seg[id].tag ^= 1;
    swap(seg[id].ans[0], seg[id].ans[1]);
    swap(seg[id].pre[0], seg[id].pre[1]);
    swap(seg[id].suf[0], seg[id].suf[1]);
}

void push(int id, int l, int r) {
    if (l == r) return;
    if (seg[id].tag) {
        apply(id*2+1);
        apply(id*2+2);
        seg[id].tag = 0;
    }
}

node merge(const node& L, const node& R) {
    node res;
    for (int i = 0; i < 2; ++i) {
        res.pre[i] = L.pre[i];
        res.suf[i] = R.suf[i];
        if (res.pre[i] == L.len) 
            res.pre[i] += R.pre[i];
        if (res.suf[i] == R.len) 
            res.suf[i] += L.suf[i];
        res.ans[i] = max({L.ans[i], R.ans[i], L.suf[i]+R.pre[i]});
    }
    res.len = L.len + R.len;
    return res;
}

void build(int id, int l, int r, string &s) {
    if (l == r) {
        seg[id] = node(s[l]);
        return;
    }
    int mid = (l+r)/2;
    build(id*2+1, l, mid, s);
    build(id*2+2, mid+1, r, s);
    seg[id] = merge(seg[id*2+1], seg[id*2+2]);
}

void update(int id, int l, int r, int ll, int rr) {
    push(id, l, r);
    if (rr < l || r < ll) return;
    if (ll <= l && r <= rr) {
        apply(id);
        return;
    }
    int mid = (l+r)/2;
    update(id*2+1, l, mid, ll, rr);
    update(id*2+2, mid+1, r, ll, rr);
    seg[id] = merge(seg[id*2+1], seg[id*2+2]);
}

node query(int id, int l, int r, int ll, int rr) {
    push(id, l, r);
    if (rr < l || r < ll) return node();
    if (ll <= l && r <= rr) return seg[id]; 
    int mid = (l+r)/2;
    auto L = query(id*2+1, l, mid, ll, rr);
    auto R = query(id*2+2, mid+1, r, ll, rr);
    return merge(L, R);
}

void solve(int T) {    
    // cout << "Case #" << T+1 << ": ";

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    // goal: 
    // c = 1, flip all
    // c = 2, find the maximum consecutive 1 in range [l,r]

    // idea:
    // segment tree

    build(0, 0, n-1, s);
    for (int i = 0; i < q; ++i) {
        int c, l, r;
        cin >> c >> l >> r;
        --l, --r;
        if (c == 1) {
            update(0, 0, n-1, l, r);
        }
        else {
            auto res = query(0, 0, n-1, l, r);
            cout << res.ans[1] << '\n';
        }
    }
}            

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
