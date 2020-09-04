// Well... Hard??. just simple dfs...
// O(N^M).

vector<vector<int>> g;
int n, m;
const int dir[8][2] = {{-1, 0}, {1, 0}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1}, {0, 1}, {0, -1}};

int dfs(int x, int y){
    int res = 1;
    g[x][y] = 0;
    for(int k = 0; k < 8; ++k){
        int nx = x+dir[k][0], ny = y+dir[k][1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || !g[nx][ny]) continue;
        res += dfs(nx, ny);
    }
    return res;
}

int maxRegion(vector<vector<int>> grid) {
    g = grid;
    n = g.size(); m = g[0].size();

    int res = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(g[i][j]) res = max(res, dfs(i, j));
    return res;
}
