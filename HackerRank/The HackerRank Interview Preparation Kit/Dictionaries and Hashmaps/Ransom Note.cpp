// O(M+N). Simple.

void checkMagazine(vector<string> magazine, vector<string> note) {
    unordered_map<string, int > mp;
    for(auto &s: magazine) mp[s]++;
    for(auto &s: note){
        if(--mp[s] < 0){
            puts("No");
            return;
        }
    }
    puts("Yes");
}
