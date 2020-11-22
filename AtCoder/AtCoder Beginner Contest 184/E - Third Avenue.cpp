// use bfs. each 'a' to 'z' at most use once.
// O(HW)

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

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int mod = 1e9+7;
const int N = 2e3+5;
char g[N][N];
const int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
queue<int> te[26];
bool vis[N][N];

void solve(){
    int h, w;
    cin >> h >> w;
    int s = 0, t = 0;
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j){
            cin >> g[i][j];
            if(g[i][j] >= 'a' && g[i][j] <= 'z')
                te[g[i][j]-'a'].push(i*w+j);
            else if(g[i][j] == 'S') s = i*w+j;
            else if(g[i][j] == 'G') t = i*w+j;
        }

    queue<int> q; q.push(s);
    int res = 0;
    while(q.size()){
        for(int qs = sz(q)-1; qs >= 0; --qs){
            int pt = q.front(); q.pop();
            int x = pt/w, y = pt%w;
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            if(pt == t){
                cout << res << "\n";
                return;
            }
            if(g[x][y] >= 'a' && g[x][y] <= 'z'){
                int id = g[x][y]-'a';
                while(te[id].size()){
                    q.push(te[id].front()); te[id].pop();
                }
            }
            for(int k = 0; k < 4; ++k){
                int nx = x+dir[k][0], ny = y+dir[k][1];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w || vis[nx][ny] || g[nx][ny] == '#') continue;
                q.push(nx*w+ny);
            }
        }
        res++;
    }
    cout << -1 << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
