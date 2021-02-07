// O(NlogN). use graph structure.

vector<int> solve(vector<vector<int>>& relations) {
    unordered_map<int, set<int>> g;
    for(auto &e: relations){
        g[e[1]].insert(e[0]);
    }
    vector<int> res;
    for(auto &e: relations){
        if(g[e[0]].count(e[1])) res.push_back(e[0]);
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    return res;
}
