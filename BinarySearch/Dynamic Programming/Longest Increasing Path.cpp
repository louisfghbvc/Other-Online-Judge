// O(NM). so just do once cuz no need to go back. monotonous. go all 4 case.

vector<vector<int>> mat;
vector<vector<int>> dp;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
int dfs(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] = 1;
    for(int k = 0; k < 4; ++k){
        int nx = i+dir[k][0], ny = j+dir[k][1];
        if(nx >= n || ny >= m || nx < 0 || ny < 0) continue;
        if(mat[i][j] < mat[nx][ny])
            dp[i][j] = max(1+dfs(nx, ny), dp[i][j]);
    }
    return dp[i][j];
}

int solve(vector<vector<int>>& matrix) {
    n = matrix.size();
    if(!n) return 0;
    m = matrix[0].size();
    mat = matrix;
    dp = vector<vector<int>> (n, vector<int>(m, -1));
    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            res = max(res, dfs(i, j));
        }
    }
    return res;
}
