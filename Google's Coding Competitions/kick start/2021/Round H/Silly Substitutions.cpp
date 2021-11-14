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
/*
**/

void solve(int T){
    printf("Case #%d: ", ++T);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vi pre(n), nxt(n), tmp(n);
    vector<bool> alive(n, true);

    for(int i = 0; i < n; ++i){
        pre[i] = i-1;
        nxt[i] = i+1;
        tmp[i] = s[i] - '0';
    }

    set<array<int, 3>> cur;
    for(int i = 0; i + 1 < n; ++i){
        cur.insert({tmp[i], tmp[i + 1], i});
    }

    auto change_ = [&] (int i, int fin){
        int z = nxt[i];
        cur.erase({tmp[i], tmp[z], i});
        int zz = nxt[z];
        alive[z] = false;
        nxt[i] = zz;
        if (zz < n){ // erase nxt-nxt
            cur.erase({tmp[z], tmp[zz], z});
            pre[zz] = i;
            cur.insert({fin, tmp[zz], i});
        }
        int p = pre[i];
        if (p >= 0){ // erase pre-i
            cur.erase({tmp[p], tmp[i], p});
            cur.insert({tmp[p], fin, p});
        }
        tmp[i] = fin;
 	};

    bool ch = true;
    while(ch){
        ch = 0;
        for(int k = 0; k <= 9; ++k){
            int nx = (k == 9 ? 0 : k + 1);
            while (true){
                auto it = cur.lower_bound({k, nx, -1});
                if (it == cur.end()) break;
                auto X = *it;
                if (X[0] == k && X[1] == nx){
                    change_(X[2], (nx + 1)%10);
                    ch = true;
                }
                else{
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i)
        if(alive[i])
            cout << char('0' + tmp[i]);
    cout << "\n";
}   
 
int main()
{
    // Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    louisfghbvc
        solve(tt);
    return 0;
}
