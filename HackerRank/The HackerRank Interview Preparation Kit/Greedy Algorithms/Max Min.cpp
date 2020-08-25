// like sliding window
// but sort
int maxMin(int k, vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int mn = INT_MAX;
    for(int r = 0, l = 0; r < n; ++r){
        if(r-l+1 > k) l++;
        if(r-l+1 == k){
            mn = min(mn, arr[r]-arr[l]);
        }
    }
    return mn;
}
