// Nothing special just can from prev, and prev2
// O(N)

int maxSubsetSum(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n+1);
    for(int i = 0; i < n; ++i){
        int mx = arr[i];
        if(i) mx = max(mx, dp[i-1]);
        if(i >= 2) mx = max(mx, dp[i-2] + arr[i]);
        dp[i] = mx;
    }
    return dp[n-1];
}
