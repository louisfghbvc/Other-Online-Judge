// use two map, also can just use one map to make target to new value. will be faster.
// if use two map, just like union-find.

unordered_map<int, int> p;
unordered_map<int, int> sz;
int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]);
}
// Complete the maxCircle function below.
vector<int> maxCircle(vector<vector<int>> queries) {
    p.clear();
    sz.clear();
    vector<int> res;
    int mx = 0;
    for(auto &q: queries){
        int a = q[0], b = q[1];
        if(!p.count(a)){
            p[a] = a;
            sz[a] = 1;
        }
        if(!p.count(b)){
            p[b] = b;
            sz[b] = 1;
        }
        a = find(a), b = find(b);
        if(a != b){
            sz[a] += sz[b];
            sz[b] = 0;
            p[b] = a;
        }
        mx = max(mx, sz[a]);
        res.push_back(mx);
    }

    return res;
}
