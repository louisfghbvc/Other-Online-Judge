#include <bits/stdc++.h>
 
// #pragma GCC optimize("O3")
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }
 
const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
1
214
**/
 
void solve(int T){
    LL k;
    cin >> k;
 
    vi digit(20);
    vi pow10(19);
 
    pow10[0] = 1;
    for(int i = 1; i <= 18; ++i)
        pow10[i] = pow10[i-1] * 10;
 
    LL base = 9;
    for(int i = 1; i <= 17; ++i, base *= 10){
        digit[i] = base * i;
    }
 
    int i = 1;
    for(; ; i++){
        if(digit[i] >= k){
            break;
        }
        else k -= digit[i];
    }
 
    if(i == 1){
        cout << k << "\n";
        return;
    }
 
    LL l = pow10[i-1], r = pow10[i]-1;
    while(l <= r){
        LL mid = l + (r - l)/2;
        LL midl = (mid - pow10[i-1]) * i + 1, midr = midl + i - 1; // right shift 1
        if(k > midr){
            l = mid+1;
        }
        else if(k < midl){
            r = mid-1;
        }
        else{
            string s = to_string(mid);
            // dbg_out(k, midl, midr, s);
            for(LL jj = midl; jj <= midr; ++jj){
                if(jj == k){
                    cout << s[jj-midl] << "\n";
                    return;
                }
            }
        }
    }
}  
 
int main()
{
    // Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    louisfghbvc
        solve(1);
    return 0;
}
 
/**
Enjoy the problem.
**/
