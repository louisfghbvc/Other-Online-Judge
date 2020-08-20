// O(N). use map.

int minimumSwaps(vector<int> arr) {
    int res = 0, n = arr.size();
    int mp[n+1];
    for(int i = 0; i < n; ++i) mp[arr[i]] = i;
    for(int i = 0; i < n; ++i){
        if(arr[i] != i+1){
            res++;
            int id = mp[i+1];
            mp[i+1] = i;
            mp[arr[i]] = id;
            swap(arr[i], arr[id]);
        }
    }
    return res;
}
