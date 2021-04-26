// Sort string and use prefix tree. O(nlogn + nm)
struct Trie{
    int val = 0;
    Trie* next[26] = {};
};

int add(Trie* root, string &s){
    Trie* tmp = root;
    int mx = 0;
    int level_val = 0;
    for(char c: s){
        level_val = tmp->val;
        if(!tmp->next[c-'a']){
            tmp->next[c-'a'] = new Trie();
        }
        tmp = tmp->next[c-'a'];
        mx = max(mx, level_val);
    }
    tmp->val = level_val + 1;
    return max(mx, tmp->val);
}

int solve(vector<string>& words) {
    Trie* root = new Trie();
    sort(words.begin(), words.end());
    int res = 0;
    for(auto &s: words){
        res = max(res, add(root, s));
    }
    return res;   
}
