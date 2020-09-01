// O(N^2). Naive solution. Well... Pass all test. 
// for each index try to find as max as possible.

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    int n = h.size();
    long area = 0;
    
    auto searchMax = [&](int l, int r){
        long mn = h[l], mx = 0;
        while(l >= 0 && r < n){
            mx = max(mx, mn*(r-l+1));
            if(l && h[l-1] >= mn) l--;
            else if(r+1<n && h[r+1] >= mn) r++;
            else break;
        }
        return mx;
    };
    
    for(int i = 0; i < n; ++i){
        area = max(area, searchMax(i, i));
    }
    
    return area;
}

// O(NlogN). Use Segment tree. Divide and Conquer.
// so just think about the smallest. and when remove smallest. 
// divide into (l, mid-1), (mid+1, r). note: mid = smallest value index.
// and each segment, the area width = r-1+1, height = arr[mid].

const int N = 1e5+5;
int tre[4*N], n;
vector<int> arr;

void build(int id, int l, int r){
    if(l == r){
        tre[id] = l;
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    tre[id] = (arr[tre[id*2]] < arr[tre[id*2+1]]) ? tre[id*2] : tre[id*2+1];
}

int query(int id, int l, int r, int ll, int rr){
    if(l >= ll && r <= rr) return tre[id];
    if(l > rr || r < ll) return -1;
    int mid = (l+r)/2;
    int left = query(id*2, l, mid, ll, rr);
    int right = query(id*2+1, mid+1, r, ll, rr);
    if(left == -1) return right;
    if(right == -1) return left;
    return arr[left] < arr[right] ? left: right;
}

long divide_(int l, int r){
    if(l > r) return -1;
    int mid = query(1, 0, n-1, l, r);
    return max({(long)(r-l+1)*arr[mid], divide_(l, mid-1), divide_(mid+1, r)});
}

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    n = h.size();

    // build segment tree
    arr = h;
    build(1, 0, n-1);

    return divide_(0, n-1);
}

// Better idea is use stack. a increase stack.
// so when a value < stack.top(). means stack.top() value can not use.
// pop it and calculate the area, the h = current pop. w = i - st.top()-1. need to think about it.
// because the when h pop can never use.
// add a super small value to array to easy code.
// O(N).

long largestRectangle(vector<int> h) {
    h.push_back(0);
    int n = h.size(), i = 0;
    stack<int> st;
    long area = 0;
    while(i < n){
        if(st.empty() || h[i] > h[st.top()]) st.push(i++);
        else{
            int height = h[st.top()]; st.pop();
            int width = (st.empty() ? i: i-st.top()-1);
            // cout << i << " " << height << " " << width << "\n";
            area = max(area, (long)height*width);
        }
    }
    return area;
}
