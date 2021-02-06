// O(logN). just find sum use by 3.

long fpow(long a, long b){
    long res = 1;
    while(b){
        if(b&1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
int solve(int n) {
    if(n%3 == 2) return fpow(3, n/3) * 2;
    if(n%3 == 1) return fpow(3, n/3-1) * 2 * 2;
    return fpow(3, n/3);
}
