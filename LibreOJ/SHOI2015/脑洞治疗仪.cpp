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
 
const int N = 3e2+5;
const LL INF = 1e13;
const int mod = 998244353;
const LL MXP = 1e10;
/**
**/

struct Node {
    int l, r;
    mutable int v;
    Node(int il, int ir, int iv) : l(il), r(ir), v(iv) {}
    bool operator<(const Node& o2) const {
        return l < o2.l;
    }
};

set<Node> odt;
// [l, r] -> [l, x-1], [x, r]
auto split(int x) {
    if (odt.empty() || x > odt.rbegin()->r) return odt.end();
    auto it = --odt.upper_bound({x, 0, 0});
    if (it->l == x) return it;
    int l = it->l, r = it->r, v = it->v;
    odt.erase(it);
    odt.insert(Node(l, x-1, v));
    return odt.insert(Node(x, r, v)).first;
}

void assign(int l, int r, int x) {
    auto itr = split(r+1), itl = split(l);
    odt.erase(itl, itr);
    odt.insert(Node(l, r, x));
}

// number of 1 [l, r]
int sum(int l, int r){
    auto itr = split(r+1), itl = split(l);
    int num = 0;
    for (auto &it = itl; it != itr; ++it) {
        if (it->v) num += it->r - it->l + 1;
    }
    return num;
}

void move(int l, int r, int cnt) {
    if (!cnt) return;
    auto itr = split(r+1), itl = split(l);
    for (auto &it = itl; it != itr && cnt; ++it) {
        if (it->v == 0) {
            int len = it->r - it->l + 1;
            if (cnt >= len) {
                it->v = 1;
                cnt -= len;
            }
            else {
                assign(it->l, it->l + cnt - 1, 1);
                return;
            }
        }
    }
}

int maxCount(int l, int r){
    auto itr = split(r+1), itl = split(l);
    int pre = 0, cnt = 0;
    for (auto &it = itl; it != itr; ++it) {
        if (it->v == 0) cnt = max(it->r - it->l + 1 + pre, cnt), pre += it->r - it->l + 1;
        else pre = 0;
    }
    return cnt;
}

void solve(int _) {
    int n, m;
    cin >> n >> m;
    odt.insert(Node(1, n, 1));
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r;
            cin >> l >> r;
            assign(l, r, 0);
        }
        else if (t == 1) {
            int l, r, l1, r1;
            cin >> l >> r >> l1 >> r1;
            int num = sum(l, r);
            assign(l, r, 0);
            move(l1, r1, num);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << maxCount(l, r) << "\n";
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
