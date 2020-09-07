// Classic O(N).

int fibonacci(int n) {
    // Complete the function.
    if(n <= 1) return n;
    int f0 = 0, f1 = 1, f2;
    for(int i = 2; i <= n; ++i){
        f2 = f0+f1;
        f0 = f1;
        f1 = f2;
    }
    return f2;
}
