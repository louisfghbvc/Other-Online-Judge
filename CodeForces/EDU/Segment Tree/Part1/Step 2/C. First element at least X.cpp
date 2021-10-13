#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5;

int arr[N];

struct node{
    int mx;
    node(int v = 0) : mx(v) {}
} tre[4*N];

class SegmentTree{
private:
    node combine(node l, node r){
        node res;
        res.mx = max(l.mx, r.mx);
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
    void update(int id, int l, int r, int pos, int x){
        if(l == r && r == pos){
            tre[id].mx = x;
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(id*2, l, mid, pos, x);
        else update(id*2+1, mid+1, r, pos, x);
        tre[id] = combine(tre[id*2], tre[id*2+1]);
    }
    int lower_bound(int id, int l, int r, int x){
        if(l == r) return tre[id].mx >= x ? l : -1;
        int mid = (l+r)/2;
        if(tre[id*2].mx >= x)
            return lower_bound(id*2, l, mid, x);
        return lower_bound(id*2+1, mid+1, r, x);
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
        int t; cin >> t;
        if(t == 1){ // change index x to opposite
            int i, v; cin >> i >> v;
            st.update(1, 0, n-1, i, v);
        }
        else{ // first minimum j, a[j] >= x
            int x; cin >> x;
            cout << st.lower_bound(1, 0, n-1, x) << "\n";
        }
    }
    return 0;
}
