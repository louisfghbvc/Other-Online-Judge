// O(sqrt(N)).
// careful the overflow. 
// so just try to greedy.
// the difference of the number make value biggest. think about total = 20, 10*10 is maximum
// and each pass we can preserve candies or buy all, why we can not buy some, because more is bigger.
// so maintain the minimum pass.

long minimumPasses(long m, long w, long p, long n) {
    long pass = 0;
    long candy = 0;
    long ans = LLONG_MAX;
    while(candy < n){
        // term*(m*w)+candy >= p
        long term = (m > LLONG_MAX/w) ? 0 : (p-candy)/(m*w);
        if(term <= 0){
            long tot = candy/p + m+w;
            long half = ceil((double)tot/2);
            if(m > w){
                m = max(m, half);
                w = tot-m;
            }
            else{
                w = max(w, half);
                m = tot-w;
            }
            candy %= p;
            term = 1;
        }
        candy += m > LLONG_MAX/w ? n: term*m*w;
        pass += term;
        long rem = m > LLONG_MAX/w ? 1 : (long)ceil((double)(n-candy)/(m*w));
        ans = min(ans, pass + rem);
    }
    return min(ans, pass);
}
