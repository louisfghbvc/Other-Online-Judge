// build a table record the minimum length. O(N)

int solve(vector<int>& nums, int k) {
    int n = nums.size();

    // best[i]: [0, i], smallest length sum up to k
    vector<int> best(n); 
    int res = 2*n;
    int min_so_far = n;

    unordered_map<int, int> ind; // record the value->index
    ind[0] = -1;
    int sum = 0;
    // like two sum strategy
    for(int i = 0; i < n; ++i){
        sum += nums[i];
        if(ind.count(sum - k)){
            int j = ind[sum-k];
            int dis = i - j;
            min_so_far = min(min_so_far, dis);
            // try to find another one
            if(j >= 0 && best[j] != n)
                res = min(res, best[j] + dis);
        }
        best[i] = min_so_far;
        ind[sum] = i;
    }

    return res == 2*n ? -1 : res;
}
