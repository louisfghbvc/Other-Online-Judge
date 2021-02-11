// O(N^2). 

int solve(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2) return n;
    // diff, index, len
    unordered_map<int, unordered_map<int, int>> dp;
    int res = 2;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i; ++j){
            int diff = nums[i] - nums[j];
            dp[diff][i] = dp[diff].count(j) ? dp[diff][j]+1 : 2; 
            res = max(res, dp[diff][i]);
        }
    }
    return res;
}
