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
 
const int N = 5e2+5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
**/

vector<string> arr;
vector<ii> g[N*N];
int dp[N*N];

const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve(int T){
    int h, w;
    cin >> h >> w;
    arr.resize(h);
    cin >> arr;

    auto key = [&](int i, int j){
        return i*w + j;
    };
    
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            for(int ni = max(i-2, 0); ni <= min(i+2, h-1); ++ni){
                for(int nj = max(j-2, 0); nj <= min(j+2, w-1); ++nj){
                    if(abs(ni - i) == 2 && abs(nj - j) == 2) continue;
                    g[key(i, j)].push_back({key(ni, nj), 1});
                }
            }
            for(int k = 0; k < 4; ++k){
                int ni = i+dir[k][0], nj = j+dir[k][1];
                if(ni < 0 || ni >= h || nj < 0 || nj >= w || arr[ni][nj] != '.') continue;
                g[key(i, j)].push_back({key(ni, nj), 0});
            }
        }
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 0});
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    while(sz(pq)){
        auto [c, id] = pq.top(); pq.pop();
        if(dp[id] < c) continue;
        for(auto &[nxt, wt]: g[id]){
            if(dp[nxt] > dp[id] + wt){
                dp[nxt] = dp[id] + wt;
                pq.push({dp[nxt], nxt});
            }
        }
    }
    
    cout << dp[key(h-1, w-1)] << "\n";
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
