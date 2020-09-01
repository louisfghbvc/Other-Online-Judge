// O(N). use stack easy to check.
// if counter right. check stack has correct left.

string isBalanced(string s) {
    stack<char> st;
    for(char c: s){
        if(c == '(' || c== '[' || c=='{') st.push(c);
        else{
            if(st.empty()) return "NO";
            char pr = st.top(); st.pop();
            if(pr == '(' && c != ')') return "NO";
            if(pr == '[' && c != ']') return "NO";
            if(pr == '{' && c != '}') return "NO";
        }
    }
    return st.empty() ? "YES" : "NO";
}
