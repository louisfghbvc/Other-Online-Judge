int divisibleSumPairs(int n, int k, vector<int> ar) {
    unordered_map<int, int> mp; // mod k
    int ans = 0;
    for(int x: ar){
        int re = x % k;
        if(re == 0) ans += mp[re];
        else ans += mp[k - re];
        mp[re]++;
    }
    return ans;
}
