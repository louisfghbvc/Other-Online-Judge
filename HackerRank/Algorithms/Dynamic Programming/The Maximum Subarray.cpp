vector<int> maxSubarray(vector<int> arr) {
    int mx = INT_MIN, cur = 0;
    for(int x: arr){
        cur = max(cur + x, x);
        mx = max(cur, mx);
    }
    
    int eleMX = *max_element(arr.begin(), arr.end()); 
    if(eleMX < 0) return {mx, eleMX};
    
    int tmp = 0;
    for(int x: arr){
        if(x > 0) tmp += x;
    }
    return {mx, tmp};
}
