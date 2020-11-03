// use counting sort.
// O(M+N).

int makeAnagram(string a, string b) {
    vector<int> af(26), bf(26);
    for(char &c: a) af[c-'a']++;
    for(char &c: b) bf[c-'a']++;
    int res = 0;
    vector<int> com(26);
    for(int i = 0; i < 26; ++i) com[i] = min(af[i], bf[i]);
    for(int i = 0; i < 26; ++i) res += af[i]-com[i];
    for(int i = 0; i < 26; ++i) res += bf[i]-com[i];
    return res;
}
