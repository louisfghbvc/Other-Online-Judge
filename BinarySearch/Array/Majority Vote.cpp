// O(N). O(1). major vote algorithm.

int solve(vector<int>& nums) {
    if(nums.empty()) return -1;
    int n = nums.size(), cnt = 1, val = nums[0];
    for(int i = 1; i < n; ++i){
        if(nums[i] != val){
            if(--cnt == 0){
                val = nums[i];
                cnt = 1;
            }
        }
        else cnt++;
    }
    cnt = 0;
    for(int x : nums){
        if(x == val) cnt++;
    }
    return cnt > n/2 ? val : -1;
}
