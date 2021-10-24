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

ii start_pos, end_pos;
int n;
string s;

void go1(LL &x, LL &y, char c){
    if(c == 'U') y++;
    if(c == 'D') y--;
    if(c == 'L') x--;
    if(c == 'R') x++;
}

bool good(LL time){
    LL cur = 0;
    LL mx = 0, my = 0; // movement
    LL dx = 0, dy = 0; 
    for(int i = 0; i < n; ++i)
        go1(dx, dy, s[i]);
    LL cycle = time / n;
    mx += cycle * dx;
    my += cycle * dy;
    int rem = time % n;
    for(int i = 0; i < rem; ++i)
        go1(mx, my, s[i]);
    return abs(start_pos.first+mx - end_pos.first) +
            abs(start_pos.second+my - end_pos.second) <= time;
}

void solve(int T){
    cin >> start_pos.first >> start_pos.second;
    cin >> end_pos.first >> end_pos.second;
    cin >> n >> s;
    LL l = 0, r = 1e18;
    LL ans = -1;
    while(l <= r){
        LL mid = l + (r-l)/2;
        if(good(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }
    cout << ans << "\n";
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
