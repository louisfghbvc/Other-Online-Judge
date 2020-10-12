// no queue. just formula, a can not go to b, so if c in [a, b] will never go to b. so b+1.
// O(N).

int truckTour(vector<vector<int>> petrolpumps) {
    int n = petrolpumps.size();
    vector<int> diff(n);
    for(int i = 0; i < n; ++i) diff[i] = petrolpumps[i][0]-petrolpumps[i][1];

    int start = 0;
    int pump = 0;
    for(int i = 0; i < n; ++i){
        pump += diff[i];
        if(pump < 0){
            start = i+1;
            pump = 0;
        }
    }
    
    return start;
}   
