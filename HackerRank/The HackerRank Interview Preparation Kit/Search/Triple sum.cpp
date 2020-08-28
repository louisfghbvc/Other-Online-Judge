// sort and remove duplicate. because unique triple
// O(NlogN).
// and find can use previous result. accumulate.
// also not sort b, can use upper_bound to count.

long triplets(vector<int> a, vector<int> b, vector<int> c) {
    sort(a.begin(), a.end());
    int na = unique(a.begin(), a.end())-a.begin();
    a.resize(na);
    sort(c.begin(), c.end());
    int nc = unique(c.begin(), c.end())-c.begin();
    c.resize(nc);
    sort(b.begin(), b.end());
    int nb = unique(b.begin(), b.end())-b.begin();
    b.resize(nb);

    long ans = 0;
    int id1 = 0, id2 = 0;
    for(int i = 0; i < b.size(); ++i){
        int q = b[i];
        while(id1 < na && a[id1] <= q) id1++;
        while(id2 < nc && c[id2] <= q) id2++;
        ans += (long)id1*(long)id2;
    }
    return ans;
}
