// O(ND). use counting sort calculate mid.

int activityNotifications(vector<int> expenditure, int d) {
    int res = 0;
    int n = expenditure.size();
    int arr[201] = {};
    for(int r = 0, l = 0; r < n; ++r){
        if(r-l+1 > d){
            // mid
            double lowm = -1, highm = -1;
            int sum = 0;
            for(int k = 0; k <= 200; ++k){
                sum += arr[k];
                if(sum-1 >= d/2-1 && lowm == -1) lowm = k;
                if(sum-1 >= d/2 && highm == -1) highm = k;
            }
            double mid = d&1 ? highm : (lowm+highm)/2.0;
            if(2*mid <= expenditure[r]) res++;
            arr[expenditure[l++]]--;
        }
        arr[expenditure[r]]++;
    }
    return res;
}
