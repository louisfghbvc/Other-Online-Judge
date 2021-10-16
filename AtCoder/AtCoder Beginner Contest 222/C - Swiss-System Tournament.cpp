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

// C > P
// G > C
// P > G

bool isWin(char a, char b){
    if(a == 'C' && b == 'P') return true;
    if(a == 'G' && b == 'C') return true;
    if(a == 'P' && b == 'G') return true;
    return false;
}

void solve(int T){
    int n, m;
    cin >> n >> m;
    vector<string> g(2*n);
    for(int i = 0; i < 2*n; ++i)
        cin >> g[i];
    
    vector<int> rank(2*n);
    vector<int> win(2*n);
    for(int k = 0; k < 2*n; ++k) rank[k] = k;

    for(int turn = 0; turn < m; ++turn){
        for(int k = 0; k+1 < 2*n; k += 2){
            char a = g[rank[k]][turn];
            char b = g[rank[k+1]][turn];
            if(a == b) continue;
            if(isWin(a, b)) win[rank[k]]++;
            else win[rank[k+1]]++;
        }
        sort(All(rank), [&](int a, int b){
            if(win[a] != win[b]) return win[a] > win[b];
            return a < b;
        });
    }
    // cout << win << "\n";
    // cout << rank << "\n";
    for(int i = 0; i < 2*n; ++i){
        cout << rank[i]+1 << "\n";
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