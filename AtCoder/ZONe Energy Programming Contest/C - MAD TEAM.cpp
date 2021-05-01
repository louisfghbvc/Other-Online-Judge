// Tricky, Convert to yes-no problem. so just guess ans

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

const LL N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
/**
Read problem statement carefully
**/

void solve(int x){
    int n;
    cin >> n;
    vector<array<int, 5>> arr(n);
    for(auto &it: arr)
        for(int i=  0; i < 5; ++i)
            cin >> it[i];

    auto check = [&](int val){
        set<int> s;
        for(auto &a: arr){
            int bit = 0;
            for(int i = 0; i < 5; ++i){
                if(a[i] >= val)
                    bit |= (1<<i);
            }
            s.insert(bit);
        }
        for(int x: s)
            for(int y: s)
                for(int z: s)
                    if((x | y | z) == 31) return 1;
        return 0;
    };


    int l = 0, r = 1e9+1;
    int ans = 0;
    while(l < r){
        int mid = (l + r)/2;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid;
    }
    cout << ans << "\n";
}

int main()
{
    Fast;
    //freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}

/**
Enjoy the problem.
**/
