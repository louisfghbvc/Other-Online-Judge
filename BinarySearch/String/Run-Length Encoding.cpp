// O(N). Simple counting string 

string solve(string s) {
    string res = "";
    int n = s.size();
    for(int i = 0, j; i < n; i = j){
        j = i;
        int fre = 0;
        while(j < n && s[i] == s[j]) fre++, j++;
        res += to_string(fre) + s[i];
    }
    return res;
}
