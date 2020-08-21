// Just. O(N^2NlogN)
// remember combination.

int sherlockAndAnagrams(string s) {
    unordered_map<string, int> mp;
    int n = s.size(), res = 0;
    for(int i = 0; i < n; ++i){
        string t = "";
        for(int j = i; j < n; ++j){
            t += s[j];
            sort(t.begin(), t.end());
            mp[t]++;
        }
    }
    for(auto &[a, b]: mp) res += (b*(b-1))/2; 
    return res;
}
