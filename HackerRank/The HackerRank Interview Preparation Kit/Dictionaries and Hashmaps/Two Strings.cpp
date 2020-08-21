// O(M+N). Counting Sort.

string twoStrings(string s1, string s2) {
    int fre[26] = {};
    for(char &c: s1) fre[c-'a']++;
    for(char &c: s2){
        if(fre[c-'a']) return "YES";
    }
    return "NO";
}
