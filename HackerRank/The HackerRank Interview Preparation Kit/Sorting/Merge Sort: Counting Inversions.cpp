// So... Just need to notice. mid choice.
// Divide and conquer.
long countInversions(vector<int> arr) {
    int n = arr.size();
    vector<int> data(n);
    function<long(int, int)> dfs;
    dfs = [&](int l, int r){
        if(l >= r) return 0L;
        int mid = l + (r-l)/2;
        long L = dfs(l, mid);
        long R = dfs(mid+1, r);
        int lp = l, rp = mid+1;
        int id = l;
        while(lp <= mid && rp <= r){
            if(arr[lp] > arr[rp]){
                L += mid-lp+1;
                data[id++] = arr[rp++];
            }
            else data[id++] = arr[lp++];
        }
        while(lp <= mid) data[id++] = arr[lp++];
        while(rp <= r) data[id++] = arr[rp++];
        for(int i = l; i <= r; ++i)
            arr[i] = data[i];

        return L+R;
    } ;
    return dfs(0, n-1);
}
