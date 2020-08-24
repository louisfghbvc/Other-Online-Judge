// O(N).
// first shrink all string to (char, len).
// and len first count the len.
// second try to make string.

long substrCount(int n, string s) {
    s += '0';
    long res = 0;
    vector<pair<char, long>> arr;
    long len = 1;
    for(int i = 1; i <= n; ++i){
        if(s[i] != s[i-1]){
            arr.push_back({s[i-1], len});
            len = 0;
        }
        len++;
        res += len;
    }
    for(int i = 1; i+1 < arr.size(); ++i){
        if(arr[i-1].first == arr[i+1].first && arr[i].second == 1)
            res += min(arr[i-1].second, arr[i+1].second);
    }
    return res;
}
