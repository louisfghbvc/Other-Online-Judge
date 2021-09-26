/**                                          
 __         ______     __  __     __     ______     ______   ______     __  __     ______     __   __   ______    
/\ \       /\  __ \   /\ \/\ \   /\ \   /\  ___\   /\  ___\ /\  ___\   /\ \_\ \   /\  == \   /\ \ / /  /\  ___\   
\ \ \____  \ \ \/\ \  \ \ \_\ \  \ \ \  \ \___  \  \ \  __\ \ \ \__ \  \ \  __ \  \ \  __<   \ \ \'/   \ \ \____  
 \ \_____\  \ \_____\  \ \_____\  \ \_\  \/\_____\  \ \_\    \ \_____\  \ \_\ \_\  \ \_____\  \ \__|    \ \_____\ 
  \/_____/   \/_____/   \/_____/   \/_/   \/_____/   \/_/     \/_____/   \/_/\/_/   \/_____/   \/_/      \/_____/                                       
**/
#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(All(x)); x.erase(unique(All(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/
 
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }
 
const int N = 2e5+5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
/**.
5
3 -4 3 -1 6
10
I 6 2
Q 3 5
R 5 -4
Q 3 5
D 2
Q 1 5
I 2 -10
Q 1 6
R 2 -1
Q 1 6
**/

struct node{ // treap
    int val, pri, size;
    int sum, ans, preMX, sufMX;
    node* ch[2];
    node(int v) : val(v), pri(rand()), size(1){
        ch[0] = ch[1] = NULL;
        sum = ans = preMX = sufMX = v;
    }
    void reset(){
        sum = ans = preMX = sufMX = val;
    }
};

// index treap operations //
int get_size(node* r){
    return r ? r->size : 0;
}

// maximum subarray sum, only record edge maximum, trick!!
node* combine(node* root, node* l, node* r){
    if(!l || !r) return l ? l : r;
    // !!note these line can not change order!
    root->ans = max({l->ans, r->ans, l->sufMX + r->preMX});
    root->preMX = max(l->preMX, l->sum + r->preMX);
    root->sufMX = max(l->sufMX + r->sum, r->sufMX);
    root->sum = l->sum + r->sum;
    return root;
}

node* pull(node *r){
    r->size = 1 + get_size(r->ch[0]) + get_size(r->ch[1]);
    r->reset();
    r = combine(r, r->ch[0], r);
    r = combine(r, r, r->ch[1]);
    return r;
}

// split to left: < i, right: >= i 
pair<node*, node*> split(node* root, int i){
    if(!root) return {root, root};
    if(get_size(root->ch[0]) + 1 >= i){ // root in right
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

// asumption: all l element size(key) < all r element size(key)
node* merge(node *l, node *r){
    if(!r || !l) return l ? l : r;
    if(l->pri > r->pri){ // l is top
        l->ch[1] = merge(l->ch[1], r);
        return pull(l);
    }
    else{
        r->ch[0] = merge(l, r->ch[0]);
        return pull(r);
    }
}

node* insert(node* root, int i, int val){
    auto p = split(root, i);
    return merge(merge(p.first, new node(val)), p.second);
}

// careful size treap !!! size is dynamic!
node* erase(node* root, int i){
    auto a = split(root, i+1);
    auto b = split(a.first, i);
    delete b.second;
    return merge(b.first, a.second);
}

// traversal dfs. debug
void print(node *root){
    if(!root) return;
    print(root->ch[0]);
    cout << root->val << " ";
    print(root->ch[1]);
}

// maximum subarray sum in range [l, r]
int range_query(node* root, int l, int r){
    auto a = split(root, r+1);
    auto b = split(a.first, l);
    int ans = b.second->ans;
    merge(b.first, b.second);
    merge(a.first, a.second);
    return ans;
}

void solve(int T){
    int n;
    cin >> n;
    node* treap = NULL;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        treap = merge(treap, new node(x));
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        int x, y;
        cin >> c;
        if(c == 'I'){ // insert y into index x
            cin >> x >> y;
            treap = insert(treap, x, y);
        }
        else if(c == 'D'){ // delete element at index x
            cin >> x;
            treap = erase(treap, x);
        }
        else if(c == 'R'){ // replace element at index x with y
            cin >> x >> y;
            treap = erase(treap, x);
            treap = insert(treap, x, y);
        }
        else{ // query maximum subarray sum of [l, r]
            cin >> x >> y;
            cout << range_query(treap, x, y) << "\n";
        }
    }
}
 
int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}
