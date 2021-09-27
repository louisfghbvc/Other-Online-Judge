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
**/
 
struct node{ // treap node
    int pri, size;
    char val;
    node* ch[2];
    node(char c) : val(c), pri(rand()), size(1){
        ch[0] = ch[1] = NULL;
    }
};
 
class treap{
private:
    node* rt;
 
    int get_size(node* r){
        return r ? r->size : 0;
    }
 
    node* pull(node *r){
        r->size = 1 + get_size(r->ch[0]) + get_size(r->ch[1]);
        return r;
    }
 
    pair<node*, node*> split(node* root, int i){ // left < i, right >= i
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
 
public:
    treap() : rt(NULL) {} 
    void push_back(char c){
        rt = merge(rt, new node(c));
    }
    void cut_paste(int l, int r){
        auto a = split(rt, r+1);
        auto b = split(a.first, l);
        rt = merge(merge(b.first, a.second), b.second);
    }
    void print(){
        print(rt);
        cout << "\n";
    }
    void print(node* root){
        if(!root) return;
        print(root->ch[0]);
        cout << root->val;
        print(root->ch[1]);
    }
};
 
 
void solve(int T){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
 
    treap tp;
    for(char c: s)
        tp.push_back(c);
 
    while(m--){
        int l, r;
        cin >> l >> r;
        tp.cut_paste(l, r);
    }
 
    tp.print();
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
