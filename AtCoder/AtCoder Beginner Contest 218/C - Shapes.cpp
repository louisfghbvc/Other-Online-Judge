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
 
const int N = 5e3+5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
/**
 * 123    147    741
 * 456 -> 258 -> 852
 * 789    369    963
**/

vector<string> cur;
vector<string> tar;

vector<ii> mapping(vector<string> &A){
    int n = A.size();
    vector<ii> res;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(A[i][j] == '#'){
                res.push_back({i, j});
            }
        }
    }
    return res;
}

bool same(vector<string> &a, vector<string> &b){
    vector<ii> amap = mapping(a);
    vector<ii> bmap = mapping(b);
    if(sz(amap) != sz(bmap)) return false;
    ii dif = {amap[0].first - bmap[0].first, amap[0].second - bmap[0].second};
    for(int i = 1, j = 1; i < amap.size() && j < bmap.size(); ++i, ++j){
        ii tmp = {amap[i].first - bmap[j].first, amap[i].second - bmap[j].second};
        if(dif != tmp) return false;
    }
    return true;
}

// rotate 90
void roi(vector<string> &a){
    for(int i = 0; i < a.size(); ++i){
        for(int j = i+1; j < a.size(); ++j){
            swap(a[i][j], a[j][i]);
        }
    }
    for(int i = 0; i < a.size(); ++i)
        reverse(All(a[i]));
}

void solve(int T){
    int n;
    cin >> n;
    cur.resize(n);
    tar.resize(n);
    for(int i= 0; i<n; ++i) cin >> cur[i];
    for(int i= 0; i<n; ++i) cin >> tar[i];

    for(int k = 0; k < 4; ++k){
        if(same(cur, tar)){
            cout << "Yes\n";
            return;
        }
        // for(int i = 0; i < n; ++i)
        //     cout << cur[i] << "\n";
        // cout << "\n";
        roi(cur);
    }
    cout << "No\n";
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
