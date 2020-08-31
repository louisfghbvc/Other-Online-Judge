// so the lowercase have two chioce. turn or not turn
// and just memorize.
// O(N^2).

const int N = 1005;
int dp[N][N];

bool dfs(string &a, string &b, int i, int j){
    int n = a.size(), m = b.size();
    if(i == n && j == m) return true;
    if(i == n) return false;
    if(dp[i][j] != -1) return dp[i][j];
    bool res = 0;
    if(isupper(a[i])){
        if(j < m && a[i] == b[j]) res |= dfs(a, b, i+1, j+1);
        else return dp[i][j] = 0; 
    }
    else{
        if(j < m && toupper(a[i]) == b[j]) res |= dfs(a, b, i+1, j+1);
        res |= dfs(a, b, i+1, j);
    }
    return dp[i][j] = res;
}

string abbreviation(string a, string b) {
    memset(dp, -1, sizeof dp);
    return dfs(a, b, 0, 0) ? "YES" : "NO";
}
