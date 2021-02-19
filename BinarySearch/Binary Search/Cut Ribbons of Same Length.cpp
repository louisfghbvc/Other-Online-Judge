// Binary Search, O(NlogV).
// Care the left and right pointer change.

int solve(vector<int>& ribbons, int k) {
    int l = 1, r = 1+*max_element(ribbons.begin(), ribbons.end());

    auto getSize = [&](int val){
        int res = 0;
        for(int &x: ribbons){
            res += x/val;
        }
        return res;
    };

    int res = -1;
    while(l < r){
        int mid = l + (r-l)/2;
        int sz = getSize(mid);
        if(sz >= k){
            res = max(res, mid);
            l = mid+1;
        }
        else{
            r = mid;
        }
    }   
    return res;
}
