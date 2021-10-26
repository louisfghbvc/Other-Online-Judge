// stack, going left to right
// determine the case, positive and negative
// many edge case, need care.
// O(N)

vector<int> solve(vector<int>& nums) {
    vector<int> res;
    for(int x: nums){
        // going right
        if(res.empty() || x >= 0) res.push_back(x);
        else{
            // stack is positive and smaller size
            while(res.size() && res.back() > 0 && res.back() < -x) res.pop_back();

            // stack not going right, so can push
            if(res.empty() || res.back() < 0) res.push_back(x);
            else if(res.back() == -x) res.pop_back();
        }
    }
    return res;
}
