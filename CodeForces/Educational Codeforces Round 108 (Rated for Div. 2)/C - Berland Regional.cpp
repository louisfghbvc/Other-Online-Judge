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

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 2e5+5;
const int INF = 0x3f3f3f3f;
/**
Read problem statement carefully
**/

vi U[N];

void solve(int x){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        U[i].clear();
    vi uni(n);
    vi S(n);
    cin >> uni >> S;

    for(int i = 0; i < n; ++i){
        U[uni[i]].push_back(S[i]);
    }

    vi ans(n+1);
    for(int i = 1; i <= n; ++i){
        if(sz(U[i])){
            sort(All(U[i]), greater<LL>());
            
            int z = sz(U[i]);
            vi pre(z + 3);
            for(int j = 1; j <= z; ++j)
                pre[j] = pre[j-1] + U[i][j-1];

            for(int j = 1; j <= z; ++j){
                int can_take = (z / j) * j;
                ans[j] += pre[can_take];
            }    
        }
    }

    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";

}

int main()
{
    Fast;
    louisfghbvc
        solve(tt);
    return 0;
}

/**
Enjoy the problem.
**/
