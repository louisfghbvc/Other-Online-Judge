// Solution1 use index set.

#include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/
void solve(int T){
    int n, q;
    cin >> n >> q;

    ordered_set<ii> st;
    vi arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        st.insert({arr[i], i});
    }

    for(int i = 0; i < q; ++i){
        char t; int a, b; 
        cin >> t >> a >> b;
        if(t == '!'){
            st.erase({arr[a-1], a-1});
            st.insert({b, a-1});
            arr[a-1] = b;
        }
        else{
            cout << st.order_of_key({b, mod}) - st.order_of_key({a-1, mod}) << "\n";
        }
    }
}

// Solution2, use BIT + Coordinate Compress
// note: N = 6e5
class BIT{
public:
    void add(int x, int v){
        for(++x; x < N; x += x&-x)
            data[x] += v;
    }
    int sum(int x){
        int res = 0;
        for(++x; x; x -= x&-x)
            res += data[x];
        return res;
    }
private:
    int data[N] = {};
} bt;
 
 
void solve(int T){
    int n, q;
    cin >> n >> q;
 
    // offline query
    vi arr(n);
    cin >> arr;
 
    vector<tuple<char, int, int>> query(q);
    for(auto &it: query)
        cin >> get<0>(it) >> get<1>(it) >> get<2>(it);
 
    // compression
    vi tmp;
    for(int x: arr) 
        tmp.push_back(x);
    for(auto &it: query){
        tmp.push_back(get<1>(it));
        tmp.push_back(get<2>(it));
    }
    sort_unique(tmp);
 
    auto get = [&](int x){
        return lower_bound(All(tmp), x) - tmp.begin();
    };
 
    for(LL &x: arr)
        bt.add(x = get(x), 1);
    
    for(auto &it: query){
        char t; int a, b;
        tie(t, a, b) = it;
        if(t == '!'){
            bt.add(arr[a-1], -1);
            b = get(b);
            bt.add(b, 1);
            arr[a-1] = b;
        }
        else{
            cout << bt.sum(get(b)) - bt.sum(get(a)-1) << "\n";
        }
    }
}

// Solution3, use treap as BST same as solution 1
