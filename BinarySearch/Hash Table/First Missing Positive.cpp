// solution1. Hash table to do. but to slow.

// solution2. Sort array. and iterate item.

// solution3. swap O(N) algorithms. swap nums[i] to correct position and if is exist no need to swap.
int solve(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; ++i){
        while(nums[i] >= 0 && nums[i] != i+1 && nums[i] != nums[nums[i]-1])
            swap(nums[i], nums[nums[i]-1]);
    }

    for(int i = 0; i < n; ++i){
        if(i+1 != nums[i]) return i+1;
    }

    return n+1;
}
