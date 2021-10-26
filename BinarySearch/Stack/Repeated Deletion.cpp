// consective string always twice.
// O(N), use stack

string solve(string s) {
    string res = "";

    int n = s.size();
    int i = 0;
    while(i < n){
        if(!res.empty() && res.back() == s[i]){
            int j = i;
            while(j < n && s[j] == res.back()) j++;
            res.pop_back();
            i = j;
        }
        else res.push_back(s[i++]);
    }

    return res;
}
