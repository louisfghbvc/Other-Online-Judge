// Simple go through all node. and add.

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    int res = 0;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for(int i = 0; i < n; ++i){
        for(int j=  0; j < m; ++j){
            if(!matrix[i][j]) continue;
            int cnt = 4;
            for(int k = 0; k < 4; ++k){
                int nx = i+dir[k][0], ny = j+dir[k][1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny]) cnt--; 
            }
            res += cnt;
        }
    }
    return res;
}
