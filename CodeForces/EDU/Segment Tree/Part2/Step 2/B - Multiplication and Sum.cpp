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
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
**/

LL tre[4*N]; // modify
LL value[4*N]; // calc
int n;

class SegmentTree{
private:
    const LL NON = 0;
    LL modify_op(LL a, LL b){
        return a * b % mod;
    }
    LL calc_op(LL a, LL b){
        return (a + b) % mod;
    }
public:
    SegmentTree() { for(int i = 0; i <= 4*n; ++i) tre[i] = 1; }
    void build(int id=1, int l=0, int r=n-1){
        if(l == r){
            value[id] = tre[l];
            return;
        }
        int mid = (l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        value[id] = calc_op(value[id*2], value[id*2+1]);
    }
    void modify(int ll, int rr, int v, int id=1, int l=0, int r=n-1){
        if(l > rr || r < ll) return;
        if(l >= ll && r <= rr){
            tre[id] = modify_op(tre[id], v);
            value[id] = modify_op(value[id], v);
            return;
        }
        int mid = (l+r)/2;
        modify(ll, rr, v, id*2, l, mid);
        modify(ll, rr, v, id*2+1, mid+1, r);
        value[id] = modify_op(calc_op(value[id*2], value[id*2+1]), tre[id]);
    }
    LL calc(int ll, int rr, int id=1, int l=0, int r=n-1){
        if(l > rr || r < ll) return NON;
        if(l >= ll && r <= rr) return value[id];
        int mid = (l+r)/2;
        LL tmp = calc_op(calc(ll, rr, id*2, l, mid), calc(ll, rr, id*2+1, mid+1, r));
        return modify_op(tmp, tre[id]);
    }
};

void solve(int T){
    int m;
    cin >> n >> m;

    SegmentTree st;
    st.build();

    for(int i = 0; i < m; ++i){
        int t, l, r, v;
        cin >> t;
        if(t == 1){ // modify
            cin >> l >> r >> v;
            st.modify(l, r-1, v);
        }
        else{ // calc [l, r)
            cin >> l >> r;
            cout << st.calc(l, r-1) << "\n";
        }
    }
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
