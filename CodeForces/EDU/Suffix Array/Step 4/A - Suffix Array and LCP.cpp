#include <bits/stdc++.h>
 
// #pragma GCC optimize("O3")
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
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
 
const int N = 4e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

int sa[N], rk[N<<1], oldrk[N<<1];
int lcp[N];

bool same(int a, int b, int k){
    return oldrk[a] == oldrk[b] && oldrk[a+k] == oldrk[b+k];
}

void build_sa(string s){
    s += '$';
    int n = sz(s);
    for(int i = 0; i < n; ++i) sa[i] = i, rk[i] = s[i];

    for(int k = 1; k < n; k <<= 1){
        sort(sa, sa + n, [&](int a, int b){
            return rk[a] == rk[b] ? rk[a + k] < rk[b + k] : rk[a] < rk[b];
        });
        memcpy(oldrk, rk, sizeof rk);

        rk[sa[0]] = 0;
        for(int i = 1, p = 0; i < n; ++i){
            if(same(sa[i], sa[i-1], k)) rk[sa[i]] = p;
            else rk[sa[i]] = ++p;
        }
    }
}

void build_lcp(string s){
    s += '$';
    int n = sz(s);
    int k = 0; // longest prefix of suf[i],suf[j]
    for(int i = 0; i+1 < n; ++i){ // longest to shortest
        int pi = rk[i];
        int j = sa[pi-1];
        while(s[i+k] == s[j+k]) k++;
        lcp[pi] = k;
        k = max(k-1, 0);
    }
}

void solve(int T){
    string s;
    cin >> s;
    build_sa(s);
    build_lcp(s);

    for(int i = 0; i <= sz(s); ++i)
        cout << sa[i] << " \n"[i==sz(s)];
    for(int i = 1; i <= sz(s); ++i)
        cout << lcp[i] << " ";
    cout << "\n";
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
 
/**
Enjoy the problem.
**/
