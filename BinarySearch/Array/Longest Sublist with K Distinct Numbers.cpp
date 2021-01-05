// O(N). use array as map.
// Sliding window.

int solve(int k, vector<int>& nums) {
    int mp[100005] = {}, mps = 0;
    int res = 0;
    for(int r = 0, l = 0; r < nums.size(); ++r){
        if(mp[nums[r]]++ == 0) mps++;
        if(mps <= k) res = max(res, r-l+1);
        else{
            while(mps > k){
                if(--mp[nums[l++]] == 0) mps--;
            }
        }
    }
    return res;
}
