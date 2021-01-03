// Simple O(N^2).
// Space can optimal to O(1).

vector<vector<int>> solve(vector<vector<int>>& matrix) {
    vector<vector<int>> res = matrix;
    int n = matrix.size();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            res[n-j-1][i] = matrix[i][j];
        }
    }
    return res;
}
