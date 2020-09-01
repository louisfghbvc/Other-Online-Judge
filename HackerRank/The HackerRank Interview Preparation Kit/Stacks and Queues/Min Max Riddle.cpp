// O(N). Again use increase array.
// main idea is the big value don't want to be caught by small.
// so when big is caught by small. another words, when cur val smaller than stack top. 
// pop stack and upadte the window size array.
// finally, some window size are not set. because we only find the biggest window size and biggest value.
// so from back to begin. update the small window which are not set.

vector<long> riddle(vector<long> arr) {
    arr.push_back(-1);
    int n = arr.size(), i = 0;
    vector<long> res(n-1);
    stack<long> st;
    while(i < n){
        if(st.empty() || arr[i] > arr[st.top()]) st.push(i++);
        else{
            long val = arr[st.top()]; st.pop();
            int len = st.empty() ? i : i-st.top()-1;
            res[len-1] = max(val, res[len-1]);
        }
    }
    for(int i = n-3; i >= 0; --i)
        res[i] = max(res[i], res[i+1]);
    return res;
}

// O(NlogN). Segment tree. the idea is same remove minimum. and check the window size

const int N = 1e6+5;
int tre[4*N], n;
vector<long> A;

void build(int id, int l, int r){
    if(l == r){
        tre[id] = l;
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    tre[id] = (A[tre[id*2]] < A[tre[id*2+1]]) ? tre[id*2]: tre[id*2+1];
}

int query(int id, int l, int r, int ll, int rr){
    if(l > rr || r < ll) return -1;
    if(l >= ll && r <= rr) return tre[id];
    int mid = (l+r)/2;
    int left = query(id*2, l, mid, ll, rr);
    int right = query(id*2+1, mid+1, r, ll, rr);
    if(left == -1) return right;
    if(right == -1) return left;
    return A[left] < A[right] ? left : right;
}

void setWindow(vector<long>& res, int l, int r){
    if(l > r) return;
    int mid = query(1, 0, n-1, l, r);
    res[r-l] = max(res[r-l], A[mid]);

    // cout << l << " " << r << "\n";
    // cout << "window size: " << r-l+1; 
    // cout << " candicate " << A[mid];
    // cout << " maximum " << res[r-l];
    // cout << "\n";

    setWindow(res, l, mid-1);
    setWindow(res, mid+1, r);
}

// Complete the riddle function below.
vector<long> riddle(vector<long> arr) {
    n = arr.size();
    long mn = *min_element(arr.begin(), arr.end());
    vector<long> res(n, mn);
    
    // build segment tree
    A = arr;
    build(1, 0, n-1);

    setWindow(res, 0, n-1);

    // big can cover small
    for(int i = n-2; i >= 0; --i){
        res[i] = max(res[i+1], res[i]);
    }

    return res;
}
