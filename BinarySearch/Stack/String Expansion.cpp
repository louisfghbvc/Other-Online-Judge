// O(N). use stack.

string gen(int n, string &s){
    string res = "";
    for(int i = 0; i < n; ++i) res += s;
    return res;
}

string solve(string s) {
    stack<string> st;
    stack<int> ist;
    string res = "";
    int tmp = 0;
    for(char c : s){
        if(isdigit(c)) tmp = tmp*10 + c-'0';
        else if(c == '('){
            st.push(res);
            ist.push(tmp);
            res = "";
            tmp = 0;
        }
        else if(c == ')'){
            string srep = res;
            res = st.top(); st.pop();
            int rep = ist.top(); ist.pop();
            res += gen(rep, srep);
        }
        else res += c;
    }
    return res;
}
