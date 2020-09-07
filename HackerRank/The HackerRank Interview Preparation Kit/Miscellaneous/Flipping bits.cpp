// O(1).

long flippingBits(long n) {
    long mask = (1LL<<32)-1;
    return n^mask;
}
