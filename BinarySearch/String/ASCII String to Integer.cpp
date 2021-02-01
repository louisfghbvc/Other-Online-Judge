// simple O(N).

int solve(string s) {
    s += "$";
    int res = 0, t = 0;
    for(char c: s){
        if(c >= '0' && c <= '9'){
            t = t*10 + c-'0';
        }
        else res += t, t = 0;
    }
    return res;
}
