// just arrange

int getMinimumCost(int k, vector<int> c) {
    int res = 0, pre = 0;
    int n = c.size();
    sort(c.rbegin(), c.rend());
    for(int i = 0, j = 0; i < n; ++i){
        if(!j) pre++;
        res += pre*c[i];
        if(++j == k) j = 0;
    }
    return res;
}
