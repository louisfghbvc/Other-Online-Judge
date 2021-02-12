// O(NM). dp + largest rectangle

int largestRect(vector<int> &a){
    a.push_back(-1);
    int n = a.size();
    int i = 0, res = 0;
    stack<int> st;
    while(i < n){
        if(st.empty() || a[st.top()] < a[i]){
            st.push(i++);
        }
        else{
            int w = a[st.top()]; st.pop();
            int h = st.size() ? i - st.top()-1 : i;
            res = max(res, w*h);
        }
    }
    a.pop_back();
    return res;
}

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if(!n) return 0;
    int m = matrix[0].size();

    vector<vector<int>> pre(n+1, vector<int>(m+1));
    /**
     1 0 0 0
     1 0 1 1
     1 0 1 1
     0 1 0 0

     1 0 0 0
     2 0 1 1
     3 0 2 2
     0 1 0 0
    **/

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(matrix[i-1][j-1]){
                pre[i][j] = pre[i-1][j] + 1;
            }
            else{
                pre[i][j] = 0;
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= n; ++i){
        res = max(res, largestRect(pre[i]));
    }
    return res;
}
