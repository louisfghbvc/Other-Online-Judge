// Sort. and compare. O(NlogN).

bool solve(vector<int>& nums) {
    int n = nums.size();
    if(!n) return true;
    vector<int> arr = nums;
    sort(arr.begin(), arr.end());
    int l = 0, r = 0;
    for(l = 0; l < n; l++){
        if(nums[l] != arr[l]) break;
    }
    for(r = n-1; r >= 0; --r){
        if(nums[r] != arr[r]) break;
    }
    if(l >= r) return true;
    // cout << l << " " << r << "\n";
    reverse(nums.begin()+l, nums.begin()+r+1);
    for(int i=  0; i < n; ++i) if(nums[i] != arr[i]) return false;
    return true;
}
