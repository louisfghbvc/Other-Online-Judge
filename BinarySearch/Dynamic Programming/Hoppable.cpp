// O(N). O(1) space.
// dp maximum hop. and when i too big break.

bool solve(vector<int>& nums) {
    int n = nums.size();

    int reach = 0;
    for(int i = 0; i < n; ++i){
        if(i > reach) break;
        reach = max(reach, i + nums[i]);
    }

    return reach >= n-1;
}
