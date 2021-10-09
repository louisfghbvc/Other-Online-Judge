// Mo's algorithm
// O(Q*sqrt(N) + N*sqrt(N) + QlogQ)

int block_sz;
struct query{
    int l, r, idx;
    bool operator<(const query &q2) const{
        if(l / block_sz != q2.l / block_sz) return l / block_sz < q2.l / block_sz;
        return r < q2.r;
    }
};
int cnt[N], ans; // MO
void add(int x){
    if(cnt[x]++ == 0) ans++;
}
void remove(int x){
    if(--cnt[x] == 0) ans--;
}

void solve(int T){
    int n, q;
    cin >> n >> q;
    vi arr(n);
    cin >> arr;
    block_sz = sqrt(n);

    auto tmp = arr;
    sort_unique(tmp);
    // compress
    for(auto &x: arr) 
        x = lower_bound(All(tmp), x) - tmp.begin();

    // offline
    vector<query> Q;
    for(int i = 0; i < q; ++i){
        int l, r; cin >> l >> r;
        Q.push_back({l-1, r-1, i});
    }
    sort(All(Q));
    vi res(q);

    ans = 0;
    int l = 0, r = 0;
    add(arr[0]);
    for(auto &[ql, qr, i]: Q){
        while(l < ql) remove(arr[l++]);
        while(r > qr) remove(arr[r--]);
        while(l > ql) add(arr[--l]);
        while(r < qr) add(arr[++r]);
        res[i] = ans;
    }

    for(int x: res)
        cout << x << "\n";
}
