// like prefix. O(N). just check current is in prevous all set.

int solve(vector<vector<string>>& contacts) {
    int n = contacts.size();
    if(!n) return 0;
    int res = 1;
    unordered_set<string> st;
    for(auto &s: contacts[0]){
        st.insert(s);
    }
    for(int i = 1; i < contacts.size(); ++i){
        bool ok = 1;
        for(auto &s: contacts[i]){
            if(st.count(s)) ok = 0;
        }
        for(auto &s: contacts[i]){
            st.insert(s);
        }
        if(ok) res++;
    }
    return res;
}
