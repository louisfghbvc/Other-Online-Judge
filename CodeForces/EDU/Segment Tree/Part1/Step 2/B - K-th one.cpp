#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5;

int arr[N];

struct node{
    int val, sum;
    node(int v = 0) : val(v), sum(v) {}
} tre[4*N];

class SegmentTree{
private:
    node combine(node l, node r){
        node res;
        res.sum = l.sum + r.sum;
        return res;
    }
public:
    SegmentTree() {}
    void build(int id, int l, int r){
        if(l == r){
            tre[id] = node(arr[l]);
            return;
        }
        int mid = (l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tre[id] = combine(tre[id*2], tre[id*2+1]);
    }
    void update(int id, int l, int r, int pos){
        if(l == r && r == pos){
            tre[id].val ^= 1;
            tre[id].sum ^= 1;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(id*2, l, mid, pos);
        else update(id*2+1, mid+1, r, pos);
        tre[id] = combine(tre[id*2], tre[id*2+1]);
    }
    int findKthOne(int id, int l, int r, int k){
        if(l == r) return l;
        int num = tre[id*2].sum;
        int mid = (l+r)/2;
        if(num >= k)
            return findKthOne(id*2, l, mid, k);
        else
            return findKthOne(id*2+1, mid+1, r, k-num);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    SegmentTree st;
    st.build(1, 0, n-1);

    while(q--){
        int t, x;
        cin >> t >> x;
        if(t == 1){ // change index x to opposite
            st.update(1, 0, n-1, x);
        }
        else{ // kth one
            cout << st.findKthOne(1, 0, n-1, x+1) << "\n";
        }
    }
    return 0;
}
