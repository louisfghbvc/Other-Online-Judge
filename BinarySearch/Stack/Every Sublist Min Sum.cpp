// very tricky. O(N).
// e.g 1 2 4 3
// 1 1 1 1
//   2 2 2
//     4 3
//       3, look it vertical

int solve(vector<int>& nums) {
    const int mod = 1e9 + 7;

    int n = nums.size();
    if(!n) return 0;

    stack<pair<int, int>> st; // value, duplicate count
    int prefix = 0, res = 0;

    // maintain monotonous stack
    for(int x: nums){
        prefix = (prefix + x) % mod;
        int dup = 1;
        while(st.size() && st.top().first > x){
            prefix -= (st.top().first * st.top().second) % mod;
            prefix += (x * st.top().second) % mod;
            if(prefix < 0) prefix += mod;
            dup += st.top().second;
            st.pop();
        }
        st.push({x, dup});
        res = (res + prefix) % mod;
    }

    return res;
}

// use set, sorted from small, O(NlogN)
int solve(vector<int>& nums) {
    const int mod = 1e9 + 7;

    int n = nums.size();
    set<int> boundary = {-1, n};
    
    // sorted from small
    vector<pair<int, int>> tmp;
    for(int i = 0; i < n; ++i)
        tmp.push_back({nums[i], i});
    sort(tmp.begin(), tmp.end());

    int res = 0;

    // for each number multiply the range
    for(auto &[val, ind]: tmp){
        auto p = boundary.upper_bound(ind);
        int l = *prev(p), r = *p;
        res += (r-ind) * 1LL * (ind-l) * 1LL * val % mod;
        res %= mod;
        if(res < 0) res += mod;
        boundary.insert(ind);
    }

    return res;
}
