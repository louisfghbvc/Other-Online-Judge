// O(N). stack.

bool match(char a, char b){
    if(a == '(' && b == ')') return true;
    if(a == '[' && b == ']') return true;
    if(a == '{' && b == '}') return true;
    return false;
}

bool solve(string s) {
    vector<char> st;
    for(char c: s){
        if(c == ')' || c == ']' || c == '}'){
            if(st.empty() || !match(st.back(), c)) return false;
            st.pop_back();
        }
        else st.push_back(c);
    }
    return st.empty();
}
