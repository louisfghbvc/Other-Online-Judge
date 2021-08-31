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
const int mod = 998244353;
/**
  merge same val to same frequencies.
  and calculate sum use math
**/

void solve(int T){
    LL n, k;
    cin >> n >> k;
    vi arr(n);
    cin >> arr;
    priority_queue<ii> pq;
    for(int i = 0; i < n; ++i){
        pq.push({arr[i], 1});
    }
    LL res = 0;
    while(sz(pq)){
        auto [val, fre] = pq.top(); pq.pop();
        if(val == 0) break;
        if(pq.size() && pq.top().first == val){
            LL ttt = pq.top().second;
            pq.pop();
            pq.push({val, ttt + fre});
            continue;
        }
        LL dif = val - (sz(pq) ? pq.top().first : 0);
        // dbg_out(val, fre, dif);
        LL nums = dif * fre;
        if(k >= nums){
            LL sum = (val + val - dif+1) * dif / 2;
            // dbg_out("first", val, "last", val - dif+1, "sum ", sum);
            res += sum * fre;
            k -= nums;
            pq.push({val - dif, fre});
        }
        else{
            LL qe = k / fre;
            // dbg_out(k, fre, qe);
            LL sum = (val + val - qe + 1) * qe / 2;
            res += sum * fre;
            // dbg_out("first", val, "last", val - qe + 1, "sum", sum);
            k -= fre * qe;
            // last
            res += (val - qe) * k;
            break;
        }
        
    }

    cout << res << "\n";
}   
 
int main()
{
    // Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
