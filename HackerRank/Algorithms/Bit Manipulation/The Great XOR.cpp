// When bit == 0 always have that bit combination possible.
// Observe.
// O(logN)

long theGreatXor(long x) {
    long res = 0;
    int bit = 0;
    while(x > 0){
        if((x & 1) == 0){
            res += (1LL<<bit);
        }
        x >>= 1;
        bit++;
    }
    return res;
}
