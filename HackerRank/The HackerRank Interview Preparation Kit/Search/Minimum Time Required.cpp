// simple binary search.
// O(NlogV).

long minTime(vector<long> machines, long goal) {
    sort(machines.begin(), machines.end());
    int n = machines.size();
    long ans = 0, l = 0, r = machines[n-1]*goal;
    while(l <= r){
        long mid = l + (r-l)/2;
        long res = 0;
        for(auto &x: machines) res += mid/x; 
        if(res >= goal){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}
