// O(N). simple two sum.

bool solve(vector<int>& nums, int k) {
    unordered_set<int> st;
    for(int x: nums){
        if(st.count(k-x)) return true;
        st.insert(x);
    }
    return false;
}
