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
5 3
2 4 7 3 5

5 4
1 2 3 4 5

4 3
1 2 4 3
**/

void solve(int n){
    int k;
    cin >> n >> k;
    vi arr(n);
    cin >> arr;

    LL tot = accumulate(All(arr), 0LL);
    LL l = 1, r = tot;

    auto divide = [&](LL mx_sum){
        LL tmp = 0;
        int group = 1;
        for(auto &v: arr){
            if(tmp + v <= mx_sum){
                tmp += v;
            }
            else{
                group++;
                tmp = v;
                if(tmp > mx_sum){
                    return k+1;
                }
            }
        }
        return group;
    };

    LL res = tot;
    while(l < r){
        LL mid = l + (r-l)/2;
        int group = divide(mid);
        if(group <= k){
            res = mid;
            r = mid;
        }
        else l = mid+1;
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
