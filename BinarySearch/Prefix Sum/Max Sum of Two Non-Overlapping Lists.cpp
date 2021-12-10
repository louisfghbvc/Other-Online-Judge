int solve(vector<int>& nums, int a, int b) {
    int n = nums.size();
    vector<int> pre(n+1);
    for(int i = 1; i <= n; ++i)
        pre[i] += pre[i-1] + nums[i-1];

    int res = -1e9;
    {
        int max_so_far = pre[a];
        for(int i = a; i < n; ++i){
            if(i + b <= n)
                res = max(res, max_so_far + pre[i+b] - pre[i]);
            max_so_far = max(max_so_far, pre[i+1] - pre[i-a+1]);
        }
    }
    swap(a, b);
    {
        int max_so_far = pre[a];
        for(int i = a; i < n; ++i){
            if(i + b <= n)
                res = max(res, max_so_far + pre[i+b] - pre[i]);
            max_so_far = max(max_so_far, pre[i+1] - pre[i-a+1]);
        }
    }
    return res;
}


// Solution2
int helper(vector<int>& nums, int a, int b){
    // two pass
    // first pass, A[i]: the maximum sum, length is a, before i
    // second pass, find length is b, pair with A[i-b]
    int n = nums.size();

    vector<int> A(n);
    int sum = 0, max_so_far = INT_MIN/2;
    for(int i = 0; i < n; ++i){
        if(i >= a) sum -= nums[i-a];
        sum += nums[i];
        if(i >= a-1){
            max_so_far = max(max_so_far, sum);
        }
        A[i] = max_so_far;
    }

    int res = INT_MIN;
    sum = 0;
    for(int i = 0; i < n; ++i){
        if(i >= b) sum -= nums[i-b];
        sum += nums[i];
        if(i >= b){
            res = max(res, sum + A[i-b]);
        }
    }
    return res; 
}

int solve(vector<int>& nums, int a, int b) {
    return max(helper(nums, a, b), helper(nums, b, a));
}
