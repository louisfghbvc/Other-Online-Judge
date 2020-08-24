// Simple LCS
// O(N^2).

int dp[5005][5005];
int commonChild(string s1, string s2) {
    int a = s1.size();
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= a; ++i){
        for(int j = 1; j <= a; ++j){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[a][a];
}
