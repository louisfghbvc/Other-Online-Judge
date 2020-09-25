// O(NlogN) merge sort... shit debug for a long time.

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

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 1e5+5;

LL n;
LL a[N];
LL tmp[N];

LL mergeS(int l, int r){
    if(l >= r) return 0;
    int mid = (l+r)/2;
    LL left = mergeS(l, mid);
    LL right = mergeS(mid+1, r);

    int i = l, j = mid+1, id = l;
    while(i <= mid && j <= r){
        if(a[i] > a[j]){
            left += (mid-i+1);
            tmp[id++] = a[j++];
        }
        else tmp[id++] = a[i++];
    }
    while(i <= mid) tmp[id++] = a[i++];
    while(j <= r) tmp[id++] = a[j++];

    for(int k = l; k <= r; ++k)
        a[k] = tmp[k];

    return left+right;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    LL t = n*(n-1)/2 - 1;
    LL res = mergeS(0, n-1);
    cout << ((res <= t) ? "YES" : "NO") << "\n";
}

int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}


// O(N). == omg. the n*(n-1)/2 is the most swap number. so just check is there exist a sorted pair.
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

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 1e5+5;

void solve(){
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    for(int i = 0; i+1 < n; ++i){
        if(a[i] <= a[i+1]){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
