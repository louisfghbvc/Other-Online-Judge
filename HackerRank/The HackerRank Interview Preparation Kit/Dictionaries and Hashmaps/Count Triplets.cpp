// Two Pass. First like prefix and suffix.
// so the pair(i, j, k) find pair A[i]/r, A[i], A[i]*r.
// first count frequency.
// O(N). and ans is (A[i]/r * A[i]*r). combination.

long countTriplets(vector<long> arr, long r) {
    int n = arr.size();
    long res = 0;
    unordered_map<long, long> rmp;
    unordered_map<long, long> lmp;
    for(auto &x: arr) rmp[x]++;
    for(int i = 0; i < n; ++i){
        rmp[arr[i]]--;
        if(arr[i] % r == 0){
            res += lmp[arr[i]/r]*rmp[arr[i]*r];
        }
        lmp[arr[i]]++;
    }
    return res;
}

// Optimal. One Pass. Amazing...
// So from end point. and check mp2. means pair. so when mp2 find means tuple.
// Why From end because Monotonous!!.
// so mp insert a value. when mp find arr[i]*r. means next time arr[i] is go to pair.
// O(N). Tricky.
long countTriplets(vector<long> arr, long r) {
    typedef pair<long, long> LL;
    int n = arr.size();
    long res = 0;
    unordered_map<long, long> mp;
    unordered_map<long, long> mp2;
    for(int i = n-1; i >= 0; --i){
        if(mp2.count(arr[i]*r)){
            res += mp2[arr[i]*r];
        }
        if(mp.count(arr[i]*r)){
            mp2[arr[i]] += mp[arr[i]*r];
        }
        mp[arr[i]]++;
    }
    return res;
}

// Other use one map<long, vector<int>>.
// left find upper_bound. right find lower_bound.
// O(NlogN)
