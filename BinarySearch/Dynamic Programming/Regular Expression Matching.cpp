// O(NM). top-down dp

int dp[1005][105];
bool dfs(string &p, string &s, int j=0, int i=0){
    if(j == p.size()) return i == s.size();
    if(dp[i][j] != -1) return dp[i][j];

    bool first = i < s.size() && (p[j] == '.' || p[j] == s[i]);
    bool ok = 0;
    if(j+1 < p.size() && p[j+1] == '*')
        ok = dfs(p, s, j+2, i) | (first && dfs(p, s, j, i+1));
    else
        ok = first && dfs(p, s, j+1, i+1);
    return dp[i][j] = ok;
}

bool solve(string pattern, string s) {
    memset(dp, -1, sizeof dp);
    return dfs(pattern, s);
}
