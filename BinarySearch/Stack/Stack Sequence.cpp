// O(N). Simulate stack.
bool solve(vector<int>& pushes, vector<int>& pops) {
    int i = 0, j = 0;
    stack<int> st;
    while(i < pushes.size() && j < pops.size()){
        bool check = (pushes[i] == pops[j]);
        st.push(pushes[i++]);
        if(check){
            while(st.size() && st.top() == pops[j]){
                st.pop();
                j++;
            }
        }
    }
    return i == pushes.size() && j == pops.size();
}
