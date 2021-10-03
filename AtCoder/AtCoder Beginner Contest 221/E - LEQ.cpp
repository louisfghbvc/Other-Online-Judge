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
 
const int N = 3e5+5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
/**
**/

struct BIT{
    LL data[N] = {};
    void add(int x, int v){
        for(++x; x < N; x+=x&-x) 
            data[x] = (data[x]+v) % mod;
    }
    LL sum(int x){
        LL res = 0;
        for(++x; x; x-=x&-x)
            res = (res + data[x]) % mod;
        return res;
    }
} bt;


LL mpow(LL a, LL b){
    LL res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        b >>= 1;
        a = a*a%mod;
    }
    return res;
}

void solve(int T){
    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;
    auto tmp = arr;
    sort_unique(tmp);

    LL inv2 = mpow(2, mod-2);

    LL res = 0;
    // go through all number
    LL prod = 1;
    for(int i = 0; i < n; ++i){
        // discrete
        int x = lower_bound(All(tmp), arr[i]) - tmp.begin();
        res = (res + prod * bt.sum(x) % mod) % mod;

        // all can append, or not append
        // for(int j = 0; j < sz(tmp); ++j)
        //     mp[j] = (mp[j] + mp[j]) % mod;

        bt.add(x, mpow(inv2, i+1));
        prod = prod * 2 % mod;
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
