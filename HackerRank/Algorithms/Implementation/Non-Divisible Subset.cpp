// O(N). Number theory.
// so use reminder. and each. only can choose left or right part.
// edge case is 0, and even k/2.

int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> fre(k, 0);
    for(int x: s) fre[x % k]++;
    
    int res = min(fre[0], 1);
    for(int l = 1, r = k-1; l < r; ++l, --r){
        res += max(fre[l], fre[r]);
    }
    if(k % 2 == 0) res += min(fre[k/2], 1);
    
    return res;
}
