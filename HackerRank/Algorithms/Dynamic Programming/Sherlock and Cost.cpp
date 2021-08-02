// A[i] is 1 or B[i]. that makes maximum

const int N = 1e5+5;
int dp[N][2];
bool vis[N][2];

int dfs(vector<int> &B, int i, bool up = 1){
    if(i+1 == B.size()) return 0;
    if(vis[i][up]) return dp[i][up];
    int val = up ? B[i] : 1;
    int res = max(abs(val - B[i+1]) + dfs(B, i+1, 1),
    abs(val - 1) + dfs(B, i+1, 0));
    vis[i][up] = 1;
    return dp[i][up] = res;
}

int cost(vector<int> B) {
    memset(dp, 0, sizeof dp);
    memset(vis, 0, sizeof vis);
    return max(dfs(B, 0, 0), dfs(B, 0, 1));
}
