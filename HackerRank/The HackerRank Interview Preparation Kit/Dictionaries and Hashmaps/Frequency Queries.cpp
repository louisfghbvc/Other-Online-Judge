// two map O(n).
// remember case 2. when mp == 0 no need to substract 1. fail many times on it.
// each operator is O(1).

vector<int> freqQuery(vector<vector<int>> queries) {
    vector<int> res;
    unordered_map<int, int> mp;
    unordered_map<int, int> fre;
    for(auto &q : queries){
        if(q[0] == 1){
            int k = ++mp[q[1]];
            // cout << q[1] << " insert, exist " << k << "\n";
            fre[k-1]--;
            fre[k]++;
        }
        else if(q[0] == 2){
            if(mp[q[1]] > 0){
                int k = --mp[q[1]];
                // cout << q[1] << " delete, exist " << k << "\n";
                fre[k+1]--;
                fre[k]++;
            }
        }
        else{
            // cout << "find " << q[1] << " " << st.count(q[1]) << "\n";
            if(fre[q[1]] > 0) res.push_back(1);
            else res.push_back(0);
        }
    }
    return res;
}
