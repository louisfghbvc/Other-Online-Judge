// O(NlogN). use multiset




// O(N), use monotonic queue
int solve(vector<int>& nums, int k) {
    deque<int> min_q, max_q;
    int window = 0;
    for(int r = 0, l = 0; r < nums.size(); ++r){
        // maintain monotonic
        while(max_q.size() && max_q.back() < nums[r]) max_q.pop_back();
        while(min_q.size() && min_q.back() > nums[r]) min_q.pop_back();
        min_q.push_back(nums[r]);
        max_q.push_back(nums[r]);
        while(max_q.front() - min_q.front() > k){
            if(max_q.front() == nums[l]) max_q.pop_front();
            if(min_q.front() == nums[l]) min_q.pop_front();
            l++;
        }
        window = max(window, r - l + 1);
    }
    return window;
}
