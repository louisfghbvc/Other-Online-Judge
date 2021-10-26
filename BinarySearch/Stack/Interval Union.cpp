// line sweep O(NlogN)
vector<vector<int>> solve(vector<vector<int>>& intervals) {
    vector<vector<int>> res;

    vector<pair<int, int>> arr;
    // 0: open, 1: close
    for(auto &v : intervals){
        arr.push_back({v[0], 0});
        arr.push_back({v[1], 1});
    }
    sort(arr.begin(), arr.end());

    int balance = 0, prev = 0;
    for(auto &[time, type]: arr){
        if(balance == 0) prev = time;

        if(type == 0) balance++;
        else balance--;

        if(balance == 0)
            res.push_back({prev, time});
    }

    return res;
}

// sort + greedy
vector<vector<int>> solve(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());

    // 0: left, 1: right
    for(auto &v: intervals){
        if(res.empty() || res.back()[1] < v[0]){
            res.push_back(v);
        }
        else{
            res.back()[1] = max(res.back()[1], v[1]);
        }
    }

    return res;
}
