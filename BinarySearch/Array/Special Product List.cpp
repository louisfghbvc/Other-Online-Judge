// O(N). space O(N). prefix + suffix
vector<int> solve(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    vector<int> suffix(n+1, 1);
    for(int i = n-2; i >= 0; --i) suffix[i] = suffix[i+1] * nums[i+1];
    int left = 1;
    for(int i = 0; i < n; ++i){
        res[i] = left * suffix[i];
        left *= nums[i];
    }
    return res;
}
