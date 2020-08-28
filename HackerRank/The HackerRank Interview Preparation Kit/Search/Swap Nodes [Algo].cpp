// Just use adjacent list to record the tree. and the tree structure will change.
// so that the adj list is useful
// O(qN)

const int N = 1025;
vector<vector<int>> g(N, vector<int>(2, 0));
int dep[N];

void dfs(int u = 1, int d = 1){
    dep[u] = d;
    if(g[u][0] != -1) dfs(g[u][0], d+1);
    if(g[u][1] != -1) dfs(g[u][1], d+1);
}

void downTree(int k, int u = 1){
    if(dep[u] % k == 0){
        swap(g[u][0], g[u][1]);
    }
    if(g[u][0] != -1) downTree(k, g[u][0]);
    if(g[u][1] != -1) downTree(k, g[u][1]);
}

void inorderT(vector<int> &ino, int u = 1){
    if(u == -1) return;
    inorderT(ino, g[u][0]);
    ino.push_back(u);
    inorderT(ino, g[u][1]);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> res; 
    int n = indexes.size();

    for(int i = 0; i < n; ++i){
        int left = indexes[i][0], right = indexes[i][1];
        g[i+1][0] = left;
        g[i+1][1] = right;
    }

    // calculate depth
    dfs();

    for(int &q: queries){
        downTree(q);
        vector<int> ans;
        inorderT(ans);
        res.push_back(ans);
    }

    return res;
}
