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
const int mod = 998244353;
/**
 just like leetcode 42.
 
 solution2, two stack, loop twice.
 
**/
 
void solve(int T){
    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;
    arr.push_back(-1);
 
    vi st;
    LL area = 0;
    for(int i = 0; i <= n; ++i){
        while(!st.empty() && arr[st.back()] > arr[i]){
            LL h = arr[st.back()]; st.pop_back();
            LL w = i - 1 - (st.empty() ? -1 : st.back());
            area = max(area, w * h);
        }
        st.push_back(i);
    }
 
    cout << area << "\n";
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

// loop twice.
void solve(int T){
    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;
 
    vi st;
    vi area(n);
    for(int i = 0; i < n; ++i){
        while(!st.empty() && arr[st.back()] >= arr[i]) st.pop_back(); // i can cover.
        LL w = i - (st.empty() ? -1 : st.back());
        area[i] += w * arr[i];
        st.push_back(i);
    }
 
    st.clear();
 
    for(int i = n-1; i >= 0; --i){
        while(!st.empty() && arr[st.back()] >= arr[i]) st.pop_back();
        LL w = (st.empty() ? n : st.back()) - i;
        area[i] += (w-1) * arr[i];
        st.push_back(i);
    }
 
    cout << *max_element(All(area)) << "\n";
}
