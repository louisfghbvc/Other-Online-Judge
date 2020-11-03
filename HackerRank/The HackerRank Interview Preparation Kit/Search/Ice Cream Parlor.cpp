// well... just two sum

void whatFlavors(vector<int> cost, int money) {
    int n = cost.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i){
        if(mp.count(money - cost[i])){
            cout << mp[money-cost[i]]+1 << " " << i+1 << "\n";
            return;
        }
        mp[cost[i]] = i;
    }
}
