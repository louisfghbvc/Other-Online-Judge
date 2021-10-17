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
 
const int N = 2e5+5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
**/

ii tre[4*N]; // prefix, minimum so far, sum
ii arr[N];
int n;

class SegmentTree{
private:
    const ii NON = {0, 0};
    ii calc_op(ii a, ii b){
        return {min(a.first, a.second + b.first), a.second + b.second};
    }
public:
    SegmentTree() {}
    void build(int id=1, int l=0, int r=n-1){
        if(l == r){
            tre[id] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tre[id] = calc_op(tre[id*2], tre[id*2+1]);
    }
    void modify(int pos, ii v, int id=1, int l=0, int r=n-1){
        if(l == r && r == pos){
            tre[id] = v;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid)
            modify(pos, v, id*2, l, mid);
        else
            modify(pos, v, id*2+1, mid+1, r);
        tre[id] = calc_op(tre[id*2], tre[id*2+1]);
    }
    ii calc(int ll, int rr, int id=1, int l=0, int r=n-1){
        if(l > rr || r < ll) return NON;
        if(l >= ll && r <= rr) return tre[id];
        int mid = (l+r)/2;
        return calc_op(calc(ll, rr, id*2, l, mid), calc(ll, rr, id*2+1, mid+1, r));
    }
};

void solve(int T){
    int m;
    cin >> n >> m;
    string s;
    cin >> s;

    for(int i = 0; i < n; ++i){
        if(s[i] == '(') arr[i] = {1, 1};
        else arr[i] = {-1, -1};
    }

    SegmentTree st;
    st.build();

    for(int i = 0; i < m; ++i){
        int t, l, r;
        cin >> t >> l >> r;
        --l, --r;
        if(t == 1){ // modify
            st.modify(l, arr[r]);
            st.modify(r, arr[l]);
            swap(arr[l], arr[r]);
        }
        else{ // calc [l, r]
            ii res = st.calc(l, r);
            if(res == make_pair(0LL, 0LL)) cout << "Yes\n";
            else cout << "No\n";
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
