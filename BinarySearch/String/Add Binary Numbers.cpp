// O(N). simple.
string solve(string a, string b) {
    string res = "";
    int carry = 0, i = (int)a.size()-1, j = (int)b.size()-1;
    while(i >= 0 || j >= 0){
        int av = (i >= 0 ? a[i--]-'0' : 0);
        int bv = (j >= 0 ? b[j--]-'0' : 0);
        int s = av+bv+carry;
        res.push_back('0'+s%2);
        carry = s/2;
    }
    if(carry) res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}
