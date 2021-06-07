#include <bits/stdc++.h>

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

struct node{
    LL to, c, d;
};

vector<node> g[N];
void solve(int T){
    int n, m;
    cin >> n >> m;
    for(int i = 0, a, b, c, d; i < m; ++i){
        cin >> a >> b >> c >> d;
        --a, --b;
        g[a].push_back({b, c, d});
        g[b].push_back({a, c, d});
    }

    vi dis(n, LLONG_MAX);
    priority_queue<ii, vector<ii>, greater<>> pq;
    pq.push({0, 0}); // cost, u

    while(pq.size()){
        auto [cost, u] = pq.top(); pq.pop();
        if(dis[u] < cost) continue;
        dis[u] = cost;

        for(node nt: g[u]){
            LL v = nt.to, w = nt.c, d = nt.d;

            auto f = [&](int j) -> double{
                return j + (double)d / (dis[u] + j + 1); 
            };

            int l = 0, r = d + 1;
            while(r - l > 2){
                int mid1 = l + (r-l) / 3, mid2 = r - (r-l) / 3;
                auto val1 = f(mid1), val2 = f(mid2); 
                if(val1 <= val2){
                    r = mid2;
                }
                else{
                    l = mid1;
                }
            }

            for(int i = l; i <= r; ++i){
                LL newD = cost + w + (LL)f(i);
                if(newD < dis[v]){
                    dis[v] = newD;
                    pq.push({newD, v});
                }
            }
        }

    }

    cout << (dis[n-1] == LLONG_MAX ? -1 : dis[n-1]) << "\n";
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
