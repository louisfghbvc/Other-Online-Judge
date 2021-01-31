// Very worth learning problem.
// first, find inverse number. and think what if shift to right change?
// use Rank tree to calculate inverse numbers.
// O(NlogN).

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

const int N = 3e5+5;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/
LL BT[N];
int arr[N];
int n;
void add(int x){
    for(; x <= n; x += x&-x)
        BT[x]++;
}
int query(int x){
    int res = 0;
    for(; x > 0; x -= x&-x)
        res += BT[x];
    return res;
}

void solve(){
    cin >> n;

    LL inv = 0;
    for(int i = 0; i < n; ++i){
        cin >> arr[i]; arr[i]++;
        inv += i - query(arr[i]);
        add(arr[i]);
    }
    int small, big;
    for(int i = 0; i < n; ++i){
        cout << inv << "\n";
        small = arr[i]-1;
        big = n - arr[i];
        inv += big - small;
    }
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}

/**
enjoy the problem.
**/
