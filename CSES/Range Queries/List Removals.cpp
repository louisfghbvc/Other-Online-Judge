// First solution BIT. tricky, use index as prefix sum
// but can not add element. not general. 

template<class T, int N> 
class BIT{
public:
    void add(int x, T v){
        for(++x; x < N; x += x&-x)
            data[x] += v;
    }
    T sum(int x){
        T res = 0;
        for(++x; x; x -= x&-x)
            res += data[x];
        return res;
    }
private:
    T data[N] = {};
};
BIT<int, N> bt;

void solve(int T){

    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;

    for(int i = 0; i < n; ++i) bt.add(i, 1);

    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        int l = 0, r = n;
        while(l < r){
            int mid = (l+r)>>1;
            if(bt.sum(mid) >= x) r = mid;
            else l = mid+1;
        }
        cout << arr[l] << " ";
        bt.add(l, -1);
    }
}

// easy Treap
struct node{
    node* ch[2];
    int val, size, pri;
    node(int v) : pri(rand()), val(v), size(1) {
        ch[0] = ch[1] = NULL;
    }
};
 
class treap{
private:
    node* rt;
    int get_size(node* r){
        return r ? r->size : 0;
    }
    node* pull(node* r){
        r->size = 1 + get_size(r->ch[0]) + get_size(r->ch[1]);
        return r;
    }
    pair<node*, node*> split(node* root, int i){ // left < i, right >= i
        if(!root) return {root, root};
        if(get_size(root->ch[0])+1 >= i){
            auto p = split(root->ch[0], i);
            root->ch[0] = p.second;
            return {p.first, pull(root)};
        }
        else{
            auto p = split(root->ch[1], i - get_size(root->ch[0]) - 1);
            root->ch[1] = p.first;
            return {pull(root), p.second};
        }
    }
    node* merge(node* l, node* r){
        if(!l || !r) return !l ? r : l;
        if(l->pri > r->pri){
            l->ch[1] = merge(l->ch[1], r);
            return pull(l);
        }
        else{
            r->ch[0] = merge(l, r->ch[0]);
            return pull(r);
        }
    }
public:
    treap(): rt(NULL) {}
    void push_back(int x){
        rt = merge(rt, new node(x));
    }
    int index_remove(int i){
        auto a = split(rt, i+1);
        auto b = split(a.first, i);
        int res = b.second->val;
        rt = merge(b.first, a.second);
        return res;
    }
};
 
void solve(int T){
    int n;
    cin >> n;
    treap tp;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        tp.push_back(x);
    }
 
    for(int i = 0; i < n; ++i){
        int p;
        cin >> p;
        cout << tp.index_remove(p) << " ";
    }
}
