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
 
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

int ID(char c){
    return islower(c) ? c - 'a' : c - 'A' + 26;
}

int Ihash(string s){
    return ID(s[0]) * 52 * 52 + ID(s[1]) * 52 + ID(s[2]); 
}

const int M = 52*52*52;
vi g[M]; // reverse graph
int cnt[M]; // indegree

void solve(int T){
    int n;
    cin >> n;
    vector<ii> E(n);
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        E[i] = {Ihash(s.substr(0, 3)), Ihash(s.substr(sz(s) - 3, 3))};
        cnt[E[i].first]++;
        g[E[i].second].push_back(E[i].first);
    }

    vi ans(M, -1);
    queue<int> q;
    for(int i = 0; i < M; ++i) if(cnt[i] == 0){
        // first go will win
        ans[i] = 0;
        q.push(i);
    }

    while(sz(q)){
        int u = q.front(); q.pop();
        if(ans[u] == 0){ // if current win, any other lose
            for(int v: g[u]){
                if(ans[v] == -1){
                    ans[v] = 1;
                    q.push(v);
                }
            }
        }
        else{
            for(int v: g[u]){
                if(--cnt[v] == 0 && ans[v] == -1){
                    ans[v] = 0;
                    q.push(v);
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(ans[E[i].second] == -1) cout << "Draw" << "\n";
        if(ans[E[i].second] == 0) cout << "Takahashi" << "\n";
        if(ans[E[i].second] == 1) cout << "Aoki" << "\n";
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
 
/**
Enjoy the problem.
**/
