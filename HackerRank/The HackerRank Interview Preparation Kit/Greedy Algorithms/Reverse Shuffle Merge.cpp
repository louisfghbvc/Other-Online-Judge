// O(N).
// reverse string, because from back to begin window.
// just need to concern reverse(A), shuffle(A) is ok. any.
// so. maintain 3 array. fre, can_use, use.
// and when use < fre/2. so add to res. or update res
// how to update? so use the array to know the remain is enough or not.
// if enough and current is smaller than now, pop it. because enough!! and substring can sperate. tricky here

string reverseShuffleMerge(string s) {
    reverse(s.begin(), s.end());

    vector<int> fre(26);
    for(char &c: s) fre[c-'a']++;
    vector<int> can_use = fre;
    
    int n = s.size();
    vector<int> used(26);
    string res = "";
    for(int i = 0; i < n; ++i){
        int id = s[i]-'a';
        if(used[id] < fre[id] / 2){
            while(res.size() && s[i] < res.back() && used[res.back()-'a'] + can_use[res.back()-'a'] > fre[res.back()-'a'] / 2){
                used[res.back()-'a']--;
                res.pop_back();
            }
            res += s[i];
            used[id]++;
            can_use[id]--;
        }
        else{
            can_use[id]--;
        }
    }

    return res;
}
