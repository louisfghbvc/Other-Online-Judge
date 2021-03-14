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

const int N = 55;
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully
sum + len*y == w
**/

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<ii> bag(n);
    for(auto &b: bag){
        cin >> b.first >> b.second;
    }
    sort(All(bag), [](auto &a, auto &b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
         });

    vi box(m);
    cin >> box;

    while(q--){
        int l, r;
        cin >> l >> r;
        --l, --r;

        multiset<int> can;
        for(int i = 0; i < m ; ++i){
            if(i >= l && i <= r) continue;
            can.insert(box[i]);
        }

        LL ans = 0;
        for(auto &b: bag){
            auto lb = can.lower_bound(b.first);
            if(lb != can.end()){
                ans += b.second;
                can.erase(lb);
            }
        }
        cout << ans << "\n";
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
Enjoy the problem.
**/
