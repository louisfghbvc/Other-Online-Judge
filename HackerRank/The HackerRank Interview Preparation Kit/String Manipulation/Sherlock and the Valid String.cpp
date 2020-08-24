// Enum, Counting sort first
// and try all possible frequency.

string isValid(string s) {
    int fre[26] = {};
    for(char c: s) fre[c-'a']++;
    function<bool()> check;
    check = [&](){
        int cnt = -1;
        for(int i = 0; i < 26; ++i) if(fre[i]){
            if(cnt == -1) cnt = fre[i];
            else if(cnt != fre[i]) return false;
        }
        return true;
    };
    if(check()) return "YES";
    for(int i = 0; i < 26; ++i){
        if(fre[i]){
            fre[i]--;
            if(check()) return "YES";
            fre[i]++;
        }
    }
    return "NO";
}
