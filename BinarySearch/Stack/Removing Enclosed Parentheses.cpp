// misunderstanding the problem... only remove outmost parenthesis

string solve(string s) {
    stack<int> idx;
    int n = s.size();

    vector<int> prev(n, -1);
    for(int i = 0; i < n; ++i){
        if(s[i] == '('){
            prev[i] = i;
            idx.push(i);
        }
        else if(s[i] == ')'){
            prev[i] = idx.top(); idx.pop();
        }
    }

    int l = 0, r = n-1;
    vector<bool> vis(n);
    while(l < r){
        if(prev[l] >= 0 && prev[r] >= 0 && prev[l] == prev[r]){
            vis[l] = vis[r] = 1;
            l++, r--;
        }
        else break;
    }
    string t = "";
    for(int i = 0; i < n; ++i){
        if(vis[i] == 0){
            t += s[i];
        }
    }
    return t;
}
