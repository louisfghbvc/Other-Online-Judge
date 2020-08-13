// so just a backtracking problem.
// dfs. if find a path return true and print route.
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long LL;
 
int g[105][105];
bool vis[105][105];
int n, m, sx, sy;
vector<ii> rt;
 
bool dfs(int x, int y, int c = 1){
    if(c == n*m){
        for(auto &x: rt)
            cout << x.first << " " << x.second << endl;
        return true;
    }
    vis[x][y] = 1;
    for(int i = 0; i < n; ++i){
        rt.push_back({i+1, y+1});
        if(!vis[i][y] && dfs(i, y, c+1)){
            return true;
        }
        rt.pop_back();
    }
    for(int j = 0; j < m; ++j){
        rt.push_back({x+1, j+1});
        if(!vis[x][j] && dfs(x, j, c+1)){
            return true;
        }
        rt.pop_back();
    }
    return false;
}
 
int main()
{
    memset(g, 0, sizeof g);
    memset(vis, 0, sizeof vis);
    cin >> n >> m >> sx >> sy;
    rt.push_back({sx, sy});
    dfs(sx-1, sy-1);
    return 0;
}
