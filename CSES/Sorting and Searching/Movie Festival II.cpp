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

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
2 1
1 2
2 3

[1, 2]
 [2, 5]
  [3, 6]
      [6, 9]
         [8, 10]
**/


void solve(int T){
    int n, k;
    cin >> n >> k;
    
    vector<ii> arr(n);
    for(auto &it : arr)
        cin >> it.first >> it.second;

    sort(All(arr));

    multiset<int> pq;
    int res = 0;
    for(int i = 0; i < n; ++i){
        // finish min
        while(sz(pq) && *pq.begin() <= arr[i].first){
            pq.erase(pq.begin());
            res++;
        } 
        pq.insert(arr[i].second);
        while(sz(pq) > k) // kill largest end
            pq.erase(pq.find(*pq.rbegin()));
    }
    res += sz(pq);
    cout << res << "\n";
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
