// Just just
int luckBalance(int k, vector<vector<int>> contests) {
    int res = 0;
    sort(contests.begin(), contests.end(), [&](vector<int> &a, vector<int>&b){
        return a[0] > b[0];
    });
    for(auto &c : contests){
        if(c[1]){
            if(--k >= 0) res += c[0];
            else res -= c[0];
        }
        else res += c[0];
    }
    return res;
}
