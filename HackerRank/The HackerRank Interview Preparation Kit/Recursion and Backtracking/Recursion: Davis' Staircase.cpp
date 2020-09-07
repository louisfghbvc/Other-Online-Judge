// same as fib. O(N).

const long mod = 1e10+7;
long dp[40];
int stepPerms(int n) {
    if(!n) return 1;
    if(dp[n]) return dp[n];
    long res = 0;
    if(n >= 1) res = (res + stepPerms(n-1)) % mod;
    if(n >= 2) res = (res + stepPerms(n-2)) % mod;
    if(n >= 3) res = (res + stepPerms(n-3)) % mod;
    return dp[n] = res;
}
