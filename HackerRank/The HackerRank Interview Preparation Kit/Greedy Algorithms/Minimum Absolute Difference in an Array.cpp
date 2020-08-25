// just adj. diff.
// O(NlogN)

int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int res = INT_MAX;
    for(int i = 0; i+1 < arr.size(); ++i){
        res = min(res, abs(arr[i]-arr[i+1]));
    }
    return res;

}
