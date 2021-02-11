// O(NM).
int solve(vector<vector<int>>& matrix) {
    if(matrix.empty()) return 0;
    int k = matrix[0].size();
    vector<int> dp(k);
    dp = matrix[0];
    for(int i = 1; i < matrix.size(); ++i){
        vector<int> dp1 = matrix[i];
        // dp1 = [2, 1, 6]
        vector<int> leftmn(k+2, 1e9), rightmn(k+2, 1e9);
        // lmn = [inf, 2, 1, 1, inf]
        // rmn = [inf, 1, 1, 6, inf]
        for(int j = 1, rj = k; j <= k; ++j, rj--){
            leftmn[j] = min(leftmn[j-1], dp[j-1]);
            rightmn[rj] = min(rightmn[rj+1], dp[rj-1]);
        }
        for(int j = 1; j <= k; ++j){
            dp1[j-1] = min(dp1[j-1] + leftmn[j-1], dp1[j-1] + rightmn[j+1]);
        }
        dp = dp1;
    }
    return *min_element(dp.begin(), dp.end());
}
