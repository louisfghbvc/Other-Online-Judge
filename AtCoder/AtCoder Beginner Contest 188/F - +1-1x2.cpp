// if u is odd, have two choice.
// else just divide by 2. until u is 0.

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 3e5+5;
const int mod = 1e9+7;


void solve(){
    LL x, y;
    cin >> x >> y;
    LL res = LLONG_MAX;
    unordered_map<LL, LL> vis;

    queue<LL> q;
    q.push(y);
    vis[y] = 0;

    while(q.size()){
        LL u = q.front(); q.pop();
        res = min(res, abs(x-u) + vis[u]);
        if(u & 1){
            if(!vis.count(u+1)){
                vis[u+1] = vis[u]+1;
                q.push(u+1);
            }
            if(!vis.count(u-1)){
                vis[u-1] = vis[u]+1;
                q.push(u-1);
            }
        }
        else{
            if(!vis.count(u>>1)){
                vis[u>>1] = vis[u]+1;
                q.push(u>>1);
            }
        }
    }

    cout << res << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}

/**
enjoy the problem.
**/
