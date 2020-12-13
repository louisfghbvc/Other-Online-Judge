// Segment tree. O(NlogN). each operation O(logN).
#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int mod = 1e9+7;
const int N = 3e5+5;

int arr[N];
int tre[4*N];

void build(int id, int l, int r){
    if(l == r){
        tre[id] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    tre[id] = tre[id*2] ^ tre[id*2+1];
}

void updateT(int id, int l, int r, int pos, int x){
    if(l == pos && r == pos){
        tre[id] ^= x;
        return;
    }
    int mid = (l+r)/2;
    if(pos <= mid) updateT(id*2, l, mid, pos, x);
    else updateT(id*2+1, mid+1, r, pos, x);
    tre[id] = tre[id*2] ^ tre[id*2+1];
}

int query(int id, int l, int r, int ll, int rr){
    if(l > rr || r < ll) return 0;
    if(r <= rr && l >= ll) return tre[id];
    int mid = (l+r)/2;
    int left = query(id*2, l, mid, ll, rr);
    int right = query(id*2+1, mid+1, r, ll, rr);
    return left^right;
}

void solve(){
    int n, q, t, l, r;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    build(1, 0, n-1);

    while(q--){
        cin >> t >> l >> r;
        if(t == 1){
            updateT(1, 0, n-1, l-1, r);
        }
        else{
            cout << query(1, 0, n-1, l-1, r-1) << "\n";
        }
    }

}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}


// BIT tree. same here with rmq.
// clean code.
#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int mod = 1e9+7;
const int N = 3e5+5;

int arr[N];
int tre[N];

void update(int i, int x){
    for(; i < N; i += (i&-i))
        tre[i] ^= x;
}

int query(int i){
    LL res = 0;
    for(; i; i -= (i&-i))
        res ^= tre[i];
    return res;
}

void solve(){
    int n, q, t, l, r;
    cin >> n >> q;

    for(int i = 0, x; i < n; ++i){
        cin >> x;
        update(i+1, x);
    }

    while(q--){
        cin >> t >> l >> r;
        if(t == 1){
            update(l, r);
        }
        else{
            cout << (query(r) ^ query(l-1)) << "\n";
        }
    }

}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
