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
 
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

int lpf[N];
int mob[N];

void init(){
    for(int i = 2; i < N; ++i){
        if(!lpf[i]){
            for(int j = i; j < N; j += i)
                if(!lpf[j]) lpf[j] = i;
        }
    }

    mob[1] = 1;
    for(int i = 2; i < N; ++i){
        if(lpf[i / lpf[i]] == lpf[i])
            mob[i] = 0;
        else
            mob[i] = -1 * mob[i / lpf[i]];
    }
}

void solve(int T){
    LL l, r;
    cin >> l >> r;
    if(l == 1) l++;

    LL res = 0;
    // gcd(x, y) == g, numbers of non-coprime pairs
    // mob[2] = -1, but we want +1
    // mob[6] = 1, but we want -1
    for(int g = 2; g <= r; ++g){
        LL cnt = r / g - (l - 1) / g;
        res -= cnt * cnt * mob[g]; // inverse sign
    }
    
    // gcd(x, y) != 1, but x / g = 1 or y / g = 1
    for(int i = l; i <= r; ++i){
        for(int j = i; j <= r; j += i){
            res--;
            if(i != j) res--;
        }
    }

    cout << res << "\n";
}   
 
int main()
{
    init();
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
