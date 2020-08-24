// case 'A' or 'B'. simple calculate 

int alternatingCharacters(string s) {
    string t = string(1, s[0]);
    for(int i = 1; i < s.size(); ++i){
        if(s[i] == t.back()) continue;
        t += s[i];
    }
    return s.size()-t.size();
}
