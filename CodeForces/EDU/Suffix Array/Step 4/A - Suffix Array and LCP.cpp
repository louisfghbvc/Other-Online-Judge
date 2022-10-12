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
 
const int N = 1e6+5;
const LL INF = 1e13;
const int mod = 1e9+7;
const LL MXP = 1e10;
/**
**/


vector<int> sa_doulbing(const string &s) {
    int n = s.size();
    vector<int> sa(n), rank(n), tmp(n);
    for (int i = 0; i < n; ++i)
        sa[i] = i, rank[i] = s[i];
    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int a, int b) {
            if (rank[a] != rank[b]) return rank[a] < rank[b];
            int ra = a+k < n ? rank[a+k] : -1;
            int rb = b+k < n ? rank[b+k] : -1;
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            tmp[sa[i]] = tmp[sa[i-1]] + cmp(sa[i-1], sa[i]);
        swap(rank, tmp);
    }
    return sa;
}

vector<int> build_lcp(const string &s, const vector<int> &sa) {
    int n = sa.size();
    vector<int> pos(n);
    for (int i = 0; i < n; ++i)
        pos[sa[i]] = i;
    vector<int> lcp(max(n-1, 0));
    int k = 0;
    for (int i = 0; i < n; ++i) {
        k = max(k-1, 0);
        if (pos[i] == n-1) {
            k = 0;
        }
        else {
            int j = sa[pos[i]+1];
            while (i+k < n && j+k < n && s[i+k] == s[j+k]) k++;
            lcp[pos[i]] = k;
        }
    }
    return lcp;
}

void solve(int T) {
    // cout << "Case #" << T+1 << ": ";
    string s;
    cin >> s;
    auto sa = sa_doulbing(s);
    auto lcp = build_lcp(s, sa);
    int n = s.size();
    cout << n;
    for (int x: sa)
        cout << " " << x;
    cout << "\n";
    cout << 0;
    for (int x: lcp)
        cout << " " << x;
    cout << "\n";
}   

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
