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

const int N = 3e5+5;
const int INF = 0x3f3f3f3f;
/**
Read problem statement carefully
**/

void solve(int x){
    int n;
    cin >> n;
    vi A(n);
    vi B(n);
    cin >> A >> B;
    int cnt = 0;
    for(int i = 1; i <= 1000; ++i){
        bool ok = 1;
        for(int j = 0; j < n; ++j){
            if(A[j] <= i && i <= B[j]);
            else ok = 0;
        }
        cnt += ok;
    }
    cout << cnt << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve(1);
    return 0;
}

/**
Enjoy the problem.
**/
