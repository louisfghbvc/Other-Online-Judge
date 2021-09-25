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
/**
**/

struct node{ // treap
    int val, pri, size;
    node* ch[2];
    node(int v) : val(v), pri(rand()), size(1){
        ch[0] = ch[1] = NULL;
    }
};

// treap operations //
int get_size(node* r){
    return r ? r->size : 0;
} 

node* pull(node *r){
    r->size = 1 + get_size(r->ch[0]) + get_size(r->ch[1]);
    return r;
}

pair<node*, node*> split(node* root, int key){
    if(!root) return {root, root};
    if(root->val >= key){ // right treap
        auto p = split(root->ch[0], key);
        root->ch[0] = p.second;
        return {p.first, pull(root)};
    }
    else{
        auto p = split(root->ch[1], key);
        root->ch[1] = p.first;
        return {pull(root), p.second};
    }
}

// assuption all key in l < all key in r
node* merge(node* l, node *r){
    if(!r) return l;
    if(!l) return r;
    if(l->pri > r->pri){
        l->ch[1] = merge(l->ch[1], r);
        return pull(l);
    }
    else{
        r->ch[0] = merge(l, r->ch[0]);
        return pull(r);
    }
}

node* insert(node *root, int val){
    auto p = split(root, val);
    return merge(merge(p.first, new node(val)), p.second);
}

node* erase(node* root, int val){
    auto a = split(root, val);
    auto b = split(a.second, val+1);
    delete b.first;
    return merge(a.first, b.second);
}

int index(node* root, int i){
    if(get_size(root->ch[0])+1 == i) return root->val;
    if(get_size(root->ch[0]) >= i) return index(root->ch[0], i);
    return index(root->ch[1], i - get_size(root->ch[0]) - 1);
}

int count(node* root, int val){
    auto p = split(root, val);
    int res = get_size(p.first);
    merge(p.first, p.second);
    return res;
}

// traversal dfs.
void print(node *root){
    if(!root) return;
    print(root->ch[0]);
    cout << root->val << " ";
    print(root->ch[1]);
}

void solve(int T){
    int q;
    cin >> q;
    node* root = NULL;
    while(q--){
        char c; int x;
        cin >> c >> x;
        if(c == 'I'){ // not existed, insert
            root = erase(root, x);
            root = insert(root, x);
        }
        else if(c == 'D'){ // existed, delete
            root = erase(root, x);
        }
        else if(c == 'K'){ // kth smallest element
            if(get_size(root) < x) cout << "invalid\n";
            else cout << index(root, x) << "\n";
        }
        else{ // count numbers of element smaller than x
            cout << count(root, x) << "\n";
        }
        // print(root); cout << "\n";
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
