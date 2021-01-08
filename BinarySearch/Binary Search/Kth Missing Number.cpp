// O(logN).

int solve(vector<int>& nums, int k) {
    if(nums.empty()) return k+1;
    int l = 0, r = nums.size();
    while(l < r){
        int mid = (l + r) / 2;
        int expect = nums[0] + mid;
        if(nums[mid] - expect > k) r = mid;
        else l = mid+1;
    }
    return nums[0] + l + k;
}
