// Just Greedy.

int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int cnt = 0, sum = 0;
    for(auto &x: prices){
        if(sum + x <= k) sum += x, cnt++;
        else break;
    }
    return cnt;
}
