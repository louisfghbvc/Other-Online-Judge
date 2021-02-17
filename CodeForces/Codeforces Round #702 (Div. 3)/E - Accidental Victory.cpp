// so choose two but when u know small value win, after this value also can win.
// binary search value that bigger than this value all can win.

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

const int N = 2e5+5;
const int mod = 1e9+7;
/**
Read problem statement carefully
1
4
1 2 4 3
5
1 1 1 1 1

**/

int n;

void solve(){
    cin >> n;
    vi arr(n);
    cin >> arr;
    LL l = *min_element(All(arr)), r = *max_element(All(arr));
    ++r;
    vi tmp = arr;
    sort(All(tmp));
    auto ok = [&](LL v){
        LL s = 0;
        for(int i = 0; i < n; ++i){
            if(tmp[i] <= v) s += tmp[i];
            else if(tmp[i] <= s) s += tmp[i];
            else return false;
        }
        return true;
    };
    while(l < r){
        LL mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else l = mid+1;
    }
    vi ans;
    for(int i = 0; i < n; ++i){
        if(arr[i] >= l) ans.push_back(i+1);
    }
    cout << sz(ans) << "\n";
    for(int x: ans)
        cout << x << " ";
    cout << "\n";
}

void init(){
}

int main()
{
    Fast;
    init();
    louisfghbvc
        solve();
    return 0;
}

/**
enjoy the problem.
**/
