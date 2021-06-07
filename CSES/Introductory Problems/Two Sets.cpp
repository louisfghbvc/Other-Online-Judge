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
1 4
2 3

14
**/

void solve(int T){
    LL n;
    cin >> n;
    LL sum = (1+n)*n/2;
    if(sum & 1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    sum >>= 1;
    vector<int> tot;
    for(int i = 1; i <= n; ++i) tot.push_back(i);
    sort(All(tot));

    vector<int> ans1, ans2;
    LL sa = 0, sb = 0;
    for(int i = n-1; i >= 0; --i){
        if(sa > sb){
            sb += tot[i];
            ans2.push_back(tot[i]);
        }
        else{
            sa += tot[i];
            ans1.push_back(tot[i]);
        }
    }

    cout << sz(ans1) << "\n";
    for(int i = 0; i < sz(ans1); ++i)
        cout << ans1[i] << " \n"[i+1==sz(ans1)];
    
    cout << sz(ans2) << "\n";
    for(int i = 0; i < sz(ans2); ++i)
        cout << ans2[i] << " \n"[i+1==sz(ans2)];
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
