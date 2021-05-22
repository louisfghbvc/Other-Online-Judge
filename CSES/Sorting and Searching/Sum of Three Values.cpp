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
4 8
2 7 5 1

**/

void solve(int n){
    LL x;
    cin >> n >> x;
    vector<ii> arr;
    for(int i = 0, tt; i < n; ++i){
        cin >> tt;
        arr.push_back({tt, i});
    }
    sort(All(arr));

    for(int i = 0; i < n; ++i){
        LL target = x - arr[i].first;
        int l = i+1, r = n-1;
        while(l < r){
            LL sum = arr[l].first + arr[r].first ;
            if(sum == target){
                cout << arr[i].second+1 << " " << arr[l].second+1 << " " << arr[r].second+1 << "\n";
                return;
            }
            else if(sum < target) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE\n";
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
