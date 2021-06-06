#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' ' << H; dbg_out(T...); }

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully

**/

LL tree[4*N];
LL arr[N];

void push(int id){
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

void build(int l, int r, int id = 1){
    if(l == r){
        tree[id] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, id * 2);
    build(mid+1, r, id * 2 + 1);
    push(id);
}

void update(int l, int r, int pos, int x, int id = 1){
    if(pos == r && l == pos){
        tree[id] = x;
        return;
    }
    int mid = (l+r)/2;
    if(mid >= pos)
        update(l, mid, pos, x, id*2);
    else
        update(mid+1, r, pos, x, id*2+1);
    push(id);
}

LL query(int l, int r, int ll, int rr, int id = 1){
    if(l > rr || r < ll) return 0;
    if(r <= rr && l >= ll) return tree[id]; // [l, r] be cover
    int mid = (l+r)/2;
    LL left = query(l, mid, ll, rr, id*2);
    LL right = query(mid+1, r, ll, rr, id*2+1);
    return left+right;
}

void solve(int T){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    build(0, n-1);
    while(q--){
        int c, a, b;
        cin >> c >> a >> b;
        if(c == 1){ // update
            update(0, n-1, a-1, b);
        }
        else{ // query
            cout << query(0, n-1, a-1, b-1) << "\n";
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

/**
Enjoy the problem.
**/
