// O(NlogN). static binary index tree.

struct BIT{
    int N;
    vector<int> fre;
    BIT(int n): N(n+1) {
        fre = vector<int>(n+1);
    } 

    void add(int x, int val){
        for(++x; x < N; x += x&-x)
            fre[x] += val;
    }

    int sum(int x){
        int res = 0;
        for(++x; x; x -= x&-x)
            res += fre[x];
        return res;
    }
};

vector<int> solve(vector<int>& lst) {
    int n = lst.size();
    if(!n) return {};

    vector<int> idx = lst;
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    // 3 4 9 6 1 -> 1 3 4 6 9
    // turn to 1 2 4 3 0
    for(int &x: lst){
        x = lower_bound(idx.begin(), idx.end(), x) - idx.begin();
    }
    BIT bt(idx.size());
    vector<int> res(n);
    for(int i = n-1; i >= 0; --i){
        res[i] = bt.sum(lst[i]-1);
        bt.add(lst[i], 1);
    }

    return res;
}
