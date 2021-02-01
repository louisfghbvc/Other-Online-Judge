// O(N^2). so cuz unique. so just use value and index. tricky.

int solve(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    for(int i = 0; i < n; ++i){
        int mn = nums[i], mx = nums[i];
        for(int j = i; j < n; ++j){
            mn = min(mn, nums[j]);
            mx = max(mx, nums[j]);
            if(j - i == mx - mn) res = max(res, j-i+1);
        }
    }
    return res;
}
