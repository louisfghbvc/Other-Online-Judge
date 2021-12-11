// O(S + T)

int solve(string source, string target) {
    // build a jump table
    int n = source.size();
    vector<int> ind(26, n);
    vector<vector<int>> nxt(n, vector<int>(26));
    for(int i = n-1; i >= 0; --i){
        ind[source[i] - 'a'] = i;
        nxt[i] = ind;
    }

    int i = n, res = 0;
    // jump the index i, until i greater than n
    for(char c: target){
        if(nxt[0][c-'a'] == n) return -1;
        if(i < n && nxt[i][c-'a'] < n){
            i = nxt[i][c-'a']+1;
        }
        else{ // restart
            i = nxt[0][c-'a']+1;
            res++;
        }
    }

    return res;
}


// space optimal, use binary search and treemap
// O(S + TlogS)
