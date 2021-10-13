#include <bits/stdc++.h>

using namespace std;
using LL = long long;
const int N = 1e5+5;

int arr[N];

struct node{
    LL sum, ans, pre, suf;
    node(int v = 0) : sum(v), ans(v), pre(v), suf(v) {}
} tre[4*N];

class SegmentTree{
private:
    node combine(node l, node r){
        node res;
        res.sum = l.sum + r.sum;
        res.ans = max({l.ans, r.ans, l.suf + r.pre});
        res.pre = max(l.pre, l.sum + r.pre);
        res.suf = max(r.suf, r.sum + l.suf);
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
            tre[id] = node(x);
            return;
        }
        int mid = (l+r)/2;
        if(pos <= mid) update(id*2, l, mid, pos, x);
        else update(id*2+1, mid+1, r, pos, x);
        tre[id] = combine(tre[id*2], tre[id*2+1]);
    }
    LL get(){
        return max(tre[1].ans, 0LL);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    SegmentTree st;
    st.build(1, 0, n-1);
    cout << st.get() << "\n";
    while(q--){
        int pos, x;
        cin >> pos >> x;
        st.update(1, 0, n-1, pos, x);
        cout << st.get() << "\n";
    }
    return 0;
}
