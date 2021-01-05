// Simple dp, from i-1, or i-2 + nums[i].
// O(N).

int solve(vector<int>& nums) {
    int n = nums.size();
    if(!n) return 0;
    int res = 0;
    for(int i = 0; i < n; ++i){
        int b2 = nums[i], b1 = nums[i];
        if(i > 0) b1 = nums[i-1];
        if(i > 1) b2 = max(b2, b2 + nums[i-2]);
        nums[i] = max(b1, b2);
    }
    for(int x: nums) res = max(res, x);
    return res;
}
