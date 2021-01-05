// Simple dp, from left or up.
// O(NM). O(1) space.

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if(!n) return 0;
    int m = matrix[0].size();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int left = matrix[i][j], up = matrix[i][j];
            if(j > 0) left += matrix[i][j-1];
            if(i > 0) up += matrix[i-1][j];
            matrix[i][j] = max(left, up);
        }
    }
    return matrix[n-1][m-1];
}
