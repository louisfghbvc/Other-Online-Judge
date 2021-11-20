struct bestK{
    // L: first k elements

    multiset<int> L, R; 
    int k;
    LL sum; // L sum

    bestK(int _k) : k(_k) { sum = 0; }

    void add(int x){
        L.insert(x);
        sum += x;
        if(L.size() > k){
            R.insert(*L.begin());
            sum -= *L.begin();
            L.erase(L.begin());
        }
    }

    void erase(int x){
        auto p = R.find(x);
        if(p != R.end()){
            R.erase(p);
            return;
        }
        L.erase(L.find(x));
        sum -= x;
        if(R.empty()) return;
        int val = *R.rbegin();
        R.erase(R.find(val));
        add(val);
    }
};

void solve(int T){
    printf("Case #%d: ", ++T);

    int d, n, k;
    cin >> d >> n >> k;

    // record each day value
    vector<vi> good(d+1); 
    vector<vi> bad(d+1); 

    for(int i = 0; i < n; ++i){
        int h, s, e;
        cin >> h >> s >> e;
        --s, --e;
        good[s].push_back(h);
        bad[e+1].push_back(h);
    }
    
    // for each day at most k attraction
    bestK containers(k);

    LL res = 0;
    for(int i = 0; i < d; ++i){
        for(auto &x: good[i])
            containers.add(x);
        for(auto &x: bad[i])
            containers.erase(x);
        res = max(res, containers.sum);
    }

    cout << res << "\n";
}   
