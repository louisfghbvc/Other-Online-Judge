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
 
const int N = 2e5+5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
**/

void compress(vector<ii>& arr){
    set<int> st;
    for(auto &it: arr)
        st.insert(it.second);
    map<int, int> idx;
    for(auto &x: st) 
        idx[x] = idx.size();
    for(auto &it: arr){
        it.second = idx[it.second];
    }
}

int val[N];
struct bit{
    void add(int x, int v){
        for(++x; x < N; x += x&-x)
            val[x] += v;
    }
    int sum(int x){
        int res = 0;
        for(++x; x; x -= x&-x)
            res += val[x];
        return res;
    }
} BIT;

void solve(int T){
    int n;
    cin >> n;
    vi A(n), B(n);
    cin >> A >> B;

    vector<ii> arr;
    // first find smaller, second bigger
    for(int i = 0; i < n; ++i){
        arr.push_back({A[i], -B[i]});
    }
    sort(All(arr));
    compress(arr);

    LL ans = 0;
    for(int i = 0; i < n; ++i){
        // find numbers of smaller than second
        LL cnt = 1;
        while(i+1 < n && arr[i] == arr[i+1]) i++, cnt++;
        ans += cnt * (cnt + BIT.sum(arr[i].second));
        // update the second value
        BIT.add(arr[i].second, cnt);
    }
    cout << ans << "\n";
}
 
int main()
{
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
