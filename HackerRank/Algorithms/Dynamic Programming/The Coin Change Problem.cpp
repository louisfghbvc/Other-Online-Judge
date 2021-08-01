long getWays(int n, vector<long> c) {
    long res = 0;
    vector<long> dp(n+1);
    dp[0] = 1;
    
    for(long x: c){
        for(int w = x; w <= n; ++w)
            dp[w] += dp[w - x];
    }
    
    return dp[n];
}
