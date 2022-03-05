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

int block_sz;
struct query{
    int l, r, idx;
    bool operator<(const query &q2) const{
        if(l / block_sz != q2.l / block_sz) return l / block_sz < q2.l / block_sz;
        return r < q2.r;
    }
};

int cnt[N];
int pr = 0;
void add(int x){
    cnt[x]++;
    if(cnt[x] % 2 == 0) pr++;
}
void remove(int x){
    cnt[x]--;
    if(cnt[x] % 2) pr--;
}

void solve(int _) {
    // use mo's    

    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;
    block_sz = sqrt(n);

    int q;
    cin >> q;
    vector<query> Q;
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        Q.push_back({l-1, r-1, i});
    }
    sort(All(Q));

    vi res(q);
    pr = 0;
    int l = 0, r = 0;
    add(arr[0]);
    for(auto &[ql, qr, i]: Q){
        while(l < ql) remove(arr[l++]);
        while(r > qr) remove(arr[r--]);
        while(l > ql) add(arr[--l]);
        while(r < qr) add(arr[++r]);
        res[i] = pr;
    }

    for(int x: res)
        cout << x << "\n";
}   

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
