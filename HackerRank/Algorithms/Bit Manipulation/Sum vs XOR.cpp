// O(N) TLE


// O(logN). just check the num bit is 0. so that bit can make 0 or 1 bit. so x2.
long sumXor(long n) {
    long res = 1;
    while(n > 0){
        if(!(n & 1)) res *= 2;
        n >>= 1;
    }
    return res;
}
