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

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
8 3
3 6 2

[0, 3], [3, 8]

[0, 3], [3, 6], [6, 8]

[0, 2], [2, 3], [3, 6], [6, 8]
**/

struct node{
    int l, r;
    node(int l = 0, int r = 0) : l(l), r(r){}
    int getD() const{
        return r-l;
    }
    bool operator<(const node &n2) const{
        int d1 = getD(), d2 = n2.getD();
        if(d1 != d2) return d1 < d2;
        return l < n2.l;
    }
};

void solve(int n){
    int x;
    cin >> x >> n;
    vi arr(n);
    cin >> arr;

    map<int, int> L2R, R2L;
    L2R[0] = x;
    R2L[x] = 0;

    set<node> tree;
    tree.insert(node(0, x));

    for(int pos: arr){
        // split 
        auto p = L2R.upper_bound(pos);
        --p;
        int l = p->first, r = p->second;

        L2R[l] = pos;
        L2R[pos] = r;

        R2L[r] = pos;
        R2L[pos] = l;

        // update tree
        tree.erase(node(l, r));
        tree.insert(node(l, pos));
        tree.insert(node(pos, r));

        cout << tree.rbegin()->getD() << "\n";    
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


// Solution2 More simple 2 set + 1 multiset.
void solve(int n){
    int x;
    cin >> x >> n;
    
    set<int> light;
    multiset<int> dis;
    light.insert(0);
    light.insert(x);
    dis.insert(x);

    for(int i = 0, p; i < n; ++i){
        cin >> p;
        auto r = light.upper_bound(p);
        auto l = prev(r);
        // split
        dis.erase(dis.find((*r) - (*l)));
        dis.insert((*r) - p);
        dis.insert(p - *l);

        light.insert(p);
        cout << *dis.rbegin() << "\n";
    }

}
