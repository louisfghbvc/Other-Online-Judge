#include <bits/stdc++.h>

using namespace std;
const int N = 2e5+5;

int arr[N];
int n;

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
    void build(int id = 1, int l = 0, int r = n-1){
        if(l == r){
            tre[id] = node(arr[l]);
            return;
        }
        int mid = (l+r)/2;
        build(id*2, l, mid);
        build(id*2+1, mid+1, r);
        tre[id] = combine(tre[id*2], tre[id*2+1]);
    }
    int lower_bound(int x, int id = 1, int l = 0, int r = n - 1){
        if(l == r){
            tre[id].mx -= x;
            return l;
        }
        int mid = (l+r)/2;
        int res = 0;
        if(tre[id*2].mx >= x)
            res = lower_bound(x, id*2, l, mid);
        else 
            res = lower_bound(x, id*2+1, mid+1, r);
        tre[id] = combine(tre[id*2], tre[id*2+1]);
        return res;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> arr[i];
    SegmentTree st;
    st.build();

    for(int i = 0; i < m; ++i){
        int g; cin >> g;
        if(tre[1].mx < g){
            cout << "0 ";
        }
        else cout << st.lower_bound(g)+1 << " ";
    }

    return 0;
}
