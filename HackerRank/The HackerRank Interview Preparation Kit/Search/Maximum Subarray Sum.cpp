// use set.
// think about BF
// and find max (prefix[i]-prefix[j] + m) % m where j = 0~i-1.
// think about if prefix[j] is smaller, prefix[i] is the ans right?
// but if a little big than prefix i, the mod will big.
// so find the upper_bound(prefix[j]) about current prefix[i]. 
// O(NlogN).

long maximumSum(vector<long> a, long m) {
    long res = 0;
    long sum = 0;
    set<long> st;
    for(long &x: a){
        sum = (sum+x)%m;
        auto it = st.upper_bound(sum);
        if(it != st.end()) res = max(res, (sum-*it+m)%m);
        st.insert(sum);
        res = max(res, sum);
    }
    return res;
}
