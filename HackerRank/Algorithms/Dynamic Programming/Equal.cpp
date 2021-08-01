int equal(vector<int> arr) {
    int mn = *min_element(arr.begin(), arr.end());
    int ans = 1e9;
    for(int x: {mn, mn - 1, mn - 2, mn - 5}){
        int ops = 0;
        for(int v: arr){
            int diff = v - x;
            ops += diff / 5;
            diff %= 5;
            ops += diff / 2;
            diff %= 2;
            ops += diff;
        }
        ans = min(ans, ops);
    }
    return ans;
}
