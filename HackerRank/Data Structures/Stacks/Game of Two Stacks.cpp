// use two prefix sum. O(NlogN).
// take the top must be continuous. so just traversal a and b.

int twoStacks(int x, vector<int> a, vector<int> b) {
    int na = a.size(), nb = b.size();
    vector<long> pre(na);
    pre[0] = a[0];
    for(int i = 1; i < na; ++i) pre[i] += pre[i-1] + a[i];

    vector<long> pre2(nb);
    pre2[0] = b[0];
    for(int i = 1; i < nb; ++i) pre2[i] += pre2[i-1] + b[i];

    int mx = 0;
    for(int i = 0; i < na && pre[i] <= x; ++i){
        int sum = pre[i];
        int target = x - sum;
        int j = upper_bound(pre2.begin(), pre2.end(), target) - pre2.begin(); --j;
        mx = max(mx, i+j+2);
    }

    for(int i = 0; i < nb && pre2[i] <= x; ++i){
        int sum = pre2[i];
        int target = x - sum;
        int j = upper_bound(pre.begin(), pre.end(), target) - pre.begin(); --j;
        mx = max(mx, i+j+2);
    }

    return mx;
}
