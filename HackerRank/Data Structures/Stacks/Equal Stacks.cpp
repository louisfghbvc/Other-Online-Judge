// Logic is simple.
// first, get minimum sum, and try to make all stack to that minimum sum.
// O(N).

#define All(x) x.begin(), x.end()
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int sum1 = accumulate(All(h1), 0);
    int sum2 = accumulate(All(h2), 0);
    int sum3 = accumulate(All(h3), 0);
    reverse(All(h1)), reverse(All(h2)), reverse(All(h3));

    while(h1.size() && h2.size() && h3.size()){
        int mn = min({sum1, sum2, sum3});
        while(h1.size() && sum1 > mn) sum1 -= h1.back(), h1.pop_back();
        while(h2.size() && sum2 > mn) sum2 -= h2.back(), h2.pop_back();
        while(h3.size() && sum3 > mn) sum3 -= h3.back(), h3.pop_back();
        if(sum1 == sum2 && sum2 == sum3) return sum1;
    }

    return 0;
}
