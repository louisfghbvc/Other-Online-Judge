// idea is first convert to palindromic string
// try to add 1 from middle to outside of string

string make_palindrome(string s){
    int l = 0, r = s.size()-1;
    while(l < r){
        s[r] = s[l];
        l++;
        r--;
    }
    return s;
}

string Solution::solve(string A) {
    string tmp = make_palindrome(A);
    if(tmp > A) return tmp;

    int n = A.size();
    int carry = 1; // change the left part
    for(int i = (n-1)/2; i >= 0; --i){
        int val = tmp[i]-'0' + carry;
        tmp[i] = '0'+val%10;
        carry = val/10;
    }

    string res = "";
    // all digit is 9
    if(carry) res = "1";
    res += tmp;
    return make_palindrome(res);
}
