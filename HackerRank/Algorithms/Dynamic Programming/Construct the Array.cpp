long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    const int mod = 1e9+7;
    
    vector<long> dp(2);
    vector<long> ndp(2);
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        // other
        ndp[1] = (dp[0] + dp[1] * (k-2) % mod) % mod;
        // one
        ndp[0] = dp[1] * (k-1) % mod;
        swap(ndp, dp);
    }
    
    return x == 1 ? dp[0] : dp[1];
}
