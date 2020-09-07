// Recursive...
// First sum it all because 10^1e5, the total maximum will be 1e5*9. if digit is 9
// and k times. so first sum them up, and do simple int recursive.

int dfs(long x){
    int res = 0;
    while(x > 0){
        res += x%10;
        x/=10;
    }
    if(res < 10) return res;
    return dfs(res);
}

// Complete the superDigit function below.
int superDigit(string n, int k) {
    long x = 0;
    for(char c: n){
        x += (long)(c-'0')*k;
    }
    return dfs(x);
}

// Math Digit root.
// O(N).

int superDigit(string n, int k) {
    int res = 0;
    for(char c: n) res += c-'0'; 
    res %= 9;
    res = res*k%9;
    if(res == 0) return 9;
    else return res;
}
