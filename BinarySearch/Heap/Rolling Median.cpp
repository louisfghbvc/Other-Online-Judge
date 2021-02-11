// Each operation is O(logN). trick
class RollingMedian {
    public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<>> big;
    RollingMedian() {

    }

    void balance(){
        if(small.size() > big.size()+1){
            big.push(small.top()); small.pop();
        }
        if(big.size() > small.size()){
            small.push(big.top()); big.pop();
        }
    }

    void add(int val) {
        if(small.empty() || small.top() > val)
            small.push(val);
        else 
            big.push(val);
        balance();
    }

    double median() {
        if(small.size() > big.size()) return small.top();
        return (double)(small.top() + big.top()) / 2;
    }
};

// use lower_bound 
// insert O(N).
class RollingMedian {
    public:
    vector<int> arr;
    RollingMedian() {

    }

    void add(int val) {
        arr.insert(lower_bound(arr.begin(), arr.end(), val), val);
    }

    double median() {
        int n = arr.size();
        if(n & 1) return arr[n/2];
        return (double)(arr[n/2] + arr[n/2-1]) / 2;
    }
};
