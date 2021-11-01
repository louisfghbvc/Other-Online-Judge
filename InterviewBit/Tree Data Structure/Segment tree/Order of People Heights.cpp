class SegmentTree{
    vector<int> tre;
    int n, size;
public:
    SegmentTree(int n) :n(n) {
        size = 1;
        while(size < n) size *= 2;
        tre.assign(2 * size, 0);
        build(1, 0, n-1);    
    }

    void build(int id, int l, int r){
        if(l == r){
            tre[id] = 1;
            return;
        }
        int mid = (l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tre[id] = tre[id*2] + tre[id*2+1];
    }

    int Kth(int k, int id, int l, int r){
        if(l == r) return l;
        int mid = (l+r)/2;
        int num = tre[id*2];
        if(num >= k) return Kth(k, id*2, l, mid);
        return Kth(k - num, id*2+1, mid+1, r);
    }

    int Kth(int k){ // 1-indexed
        return Kth(k, 1, 0, n-1);
    }

    void update(int i, int v, int id, int l, int r){
        if(l == r && i == l){
            tre[id] += v;
            return;
        }
        int mid = (l+r)/2;
        if(i <= mid) update(i, v, id*2, l, mid);
        else update(i, v, id*2+1, mid+1, r);
        tre[id] = tre[id*2] + tre[id*2+1];
    }
    void update(int i, int v){
        return update(i, v, 1, 0, n-1);
    }
};

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<int> res(n);
    SegmentTree st(n);

    vector<pair<int, int>> tmp;
    for(int i = 0; i < n; ++i) tmp.push_back({A[i], B[i]});
    sort(tmp.begin(), tmp.end());

    for(int i = 0; i < n; ++i){
        int idx = st.Kth(tmp[i].second+1);
        st.update(idx, -1);
        res[idx] = tmp[i].first;
    }

    return res;
}
