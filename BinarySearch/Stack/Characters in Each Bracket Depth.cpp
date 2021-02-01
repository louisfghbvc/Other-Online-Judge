// use stack and map.
// O(N).
vector<int> solve(string s) {
    stack<char> st;
    vector<int> res;
    int dep = 0;
    map<int, int> mp; 
    for(char c: s){
        if(c == '(') st.push(c), dep++;
        else if(c == 'X') st.push(c);
        else{
            int t = 0;
            while(st.size() && st.top() != '('){
                t++; st.pop();
            }
            mp[dep--] += t;
            st.pop();
        }
    }
    for(auto &[d, v]: mp){
        res.push_back(v);
    }
    return res;
}

// only use map, use param record max depth.
// O(N).
vector<int> solve(string s) {
    vector<int> res;
    int dep = 0, mx = 0;
    unordered_map<int, int> mp; 
    for(char c: s){
        if(c == '('){
            dep++;
            mx = max(dep, mx);
        }
        else if(c == 'X') mp[dep]++;
        else dep--;
    }
    for(int i = 1; i <= mx; ++i)
        res.push_back(mp[i]);
    return res;
}
