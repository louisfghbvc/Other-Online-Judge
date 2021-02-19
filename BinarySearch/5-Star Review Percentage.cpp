// Just math.

int solve(vector<vector<int>>& reviews, int threshold) {
    int x = 0, y = 0;
    for(auto &r: reviews){
        x += r[0];
        y += r[1];
    }
    if(threshold == 100) return 0;
    return max(0, (threshold*y - x*100 + 99 - threshold)/(100-threshold));
}
