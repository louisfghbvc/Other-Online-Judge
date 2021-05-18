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
1 2 3
  x
x   1  
**/

// if odd, fn = 2 * fn/2 + 1
// if even, fn = 2 * fn/2 - 1
// u can think small case.
int solve(int n, int k) {
    if(n % 2 == 0){
        if(k <= n/2) return 2*k;
        return 2 * solve(n >> 1, k - n/2) - 1;
    }
    else{
        if(k <= (n+1)/2){
            if(k == (n+1)/2) return 1; // last people kill 1
            else return k*2;
        }
	    return 2 * solve(n >> 1, k - (n+1)/2) + 1;
    }
}

void solve(int n){
    int k;
    cin >> n >> k;
    cout << solve(n, k) << "\n";
}

int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    louisfghbvc
        solve(1);
    return 0;
}

/**
Enjoy the problem.
**/
