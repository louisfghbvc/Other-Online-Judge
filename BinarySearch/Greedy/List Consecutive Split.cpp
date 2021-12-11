// Greedy, use pq to record the (smallest, length)
// O(NlogN)

bool solve(vector<int>& nums, int k) {
    int n = nums.size();
    if(n % k) return false;

    sort(nums.begin(), nums.end());

    // val, length
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for(int x: nums){
        while(pq.size() && pq.top().second == k) pq.pop();
        if(pq.empty() || x != pq.top().first+1) pq.push({x, 1});
        else{
            auto [a, b] = pq.top(); pq.pop();
            pq.push({x, b+1});
        }
    }
    while(pq.size() && pq.top().second == k) pq.pop();
    return pq.empty();
}

// use a hashtable, do only smallest value
