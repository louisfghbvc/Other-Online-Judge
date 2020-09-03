// Like stock span problem. the monotonous. hard to think.
// so maintain a increase stack. because the increase stack are die all in one day.
// when have decrease. update the die day. if not minimum. like dp. and merge and merge
// because all day except minimum will die.
// when single increase die_day = 1.
// O(N)

// Complete the poisonousPlants function below.
int poisonousPlants(vector<int> p) {
    int mx = 0;
    int n = p.size();
    vector<int> die_day(n);
    int mn = p[0];
    stack<int> s; s.push(0);

    for(int i = 1; i < n; ++i){
        if(p[i] > p[i-1]) die_day[i] = 1;
        mn = min(mn, p[i]);
        while(s.size() && p[s.top()] >= p[i]){
            if(p[i] > mn)
                die_day[i] = max(die_day[i], die_day[s.top()]+1);
            s.pop();
        }
        s.push(i);
        mx = max(mx, die_day[i]);
    }
    return mx;
}
