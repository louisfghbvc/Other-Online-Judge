// O(N). Backtracking. 
// First compute longest common prefix.
// fill it, then check ok. if not ok backtracking.

string solve(string digits, string lower) {
    int n = digits.size();
    lower = string(n - lower.size(), '0') + lower;
    int fre[10] = {0};
    for(char c: digits) fre[c-'0']++;

    string res = string(n, '0');
    int d = 0;
    while(fre[lower[d]-'0'] > 0) res[d] = lower[d], fre[lower[d]-'0']--, d++;

    auto helper = [&](int x){
        if(x >= lower.size()) return false;
        for(char dg = lower[x] + 1; dg <= '9'; ++dg){
            if(fre[dg-'0']){
                fre[dg-'0']--;
                res[x++] = dg;
                for(char y = '0'; y <= '9'; ++y){
                    while(fre[y-'0']){
                        fre[y-'0']--;
                        res[x++] = y;
                    }
                }
                return true;
            }
        }
        return false;
    };
    while(d >= 0 && !helper(d)) d--, ++fre[lower[d]-'0'];
    d = 0;
    while(d+1 < n && res[d] == '0') d++;
    return res.substr(d);
}
