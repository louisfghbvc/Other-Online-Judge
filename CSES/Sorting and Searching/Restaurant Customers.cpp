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

const int N = 5e3 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
3
5 8
2 4
3 9
**/

void solve(int n){
    cin >> n;
    vector<ii> arr;
    for(int i = 0, l, r; i < n; ++i){
        cin >> l >> r;
        arr.push_back({l, 1});
        arr.push_back({r, -1});
    }
    sort(All(arr));
    int flow = 0, res = 0;
    for(int i = 0; i < 2*n; ++i){
        flow += arr[i].second;
        res = max(flow, res);
    }

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

// solution2 use map. 
void solve(int n){
    cin >> n;
    map<int, int> mp;
    for(int i = 0, l, r; i < n; ++i){
        cin >> l >> r;
        mp[l]++;
        mp[r]--;
    }
 
    int flow = 0, res = 0;
    for(auto &[val, f]: mp){
        flow += f;
        res = max(flow, res);
    }
    cout << res << "\n";
}
