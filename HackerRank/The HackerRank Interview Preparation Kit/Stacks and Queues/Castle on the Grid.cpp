// BFS. O(N^2). Useful for shortest path.

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int n = grid.size(), m = grid[0].size();
    bool vis[n][m];
    memset(vis, 0, sizeof vis);

    queue<pair<int, int>> q;
    int dep = 0;
    q.push({startX, startY});
    while(q.size()){
        for(int s = q.size()-1; s >= 0; --s) {
            auto [x, y] = q.front(); q.pop();
            if(vis[x][y]) continue;
            // cout << x << " " << y << "\n";
            vis[x][y] = 1;
            if(x == goalX && y == goalY) return dep;
            // down
            for(int i = x+1; i < n; ++i) if(!vis[i][y]){
                if(grid[i][y] == 'X') break;
                q.push({i, y});
            } 
            // up
            for(int i = x-1; i >= 0; --i) if(!vis[i][y]){
                if(grid[i][y] == 'X') break;
                q.push({i, y});
            } 
            // left
            for(int i = y-1; i >= 0; --i) if(!vis[x][i]){
                if(grid[x][i] == 'X') break;
                q.push({x, i});
            }
            // right
            for(int i = y+1; i < m; ++i) if(!vis[x][i]){
                if(grid[x][i] == 'X') break;
                q.push({x, i});
            }
        }
        dep++;
    }
    return dep;
}
