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

int arr[N];
ii tre[4*N]; // min, fre

class SegmentTree{
private:
    int n;
    ii combine(ii l, ii r){
        if(l.first < r.first) return l;
        if(l.first > r.first) return r;
        return {l.first, l.second+r.second};
    }
public:
    SegmentTree(int n): n(n) {}
    void build(int id, int l, int r){
        if(l == r) return (void)(tre[id] = {arr[l], 1});
        int mid = (l+r)/2;
        build(id*2+1, l, mid);
        build(id*2+2, mid+1, r);
        tre[id] = combine(tre[id*2+1], tre[id*2+2]);
    }
    void update(int id, int l, int r, int pos, int x){
        if(l == r && pos == r) return (void)(tre[id] = {x, 1});
        int mid = (l+r)/2;
        if(mid >= pos) update(id*2+1, l, mid, pos, x);
        else update(id*2+2, mid+1, r, pos, x);
        tre[id] = combine(tre[id*2+1], tre[id*2+2]);
    }
    ii query(int id, int l, int r, int ll, int rr){
        if(r < ll || l > rr) return {INT_MAX, 0};
        if(ll <= l && r <= rr) return tre[id];
        int mid = (l+r)/2;
        return combine(
            query(id*2+1, l, mid, ll, rr),
            query(id*2+2, mid+1, r, ll, rr)
        );
    }
};

void solve(int T){
    int n, m;
    cin >> n >> m;
    SegmentTree st(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    st.build(0, 0, n-1);
    while(m--){
        int t, u, v; cin >> t >> u >> v;
        if(t == 1){ // set 
            st.update(0, 0, n-1, u, v);
        }
        else{
            ii res = st.query(0, 0, n-1, u, v-1);
            cout << res.first << " " << res.second << "\n";
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
