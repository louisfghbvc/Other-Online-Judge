// O(N). Very Tricky.
// Like Euler tour. so when into left edge + sum, out right edge - sum.

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<int> et(n+1);
    for(auto &q: queries){
        et[q[0]-1] += q[2];
        et[q[1]] -= q[2];
    }
    long sum = 0, mx = 0;
    for(int i = 0; i <= n; ++i){
        sum += et[i];
        mx = max(sum, mx);
    }
    return mx;
}
