// Enum all case. and use number root.

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

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int mod = 1e9+7;
const int N = 2e3+5;

int fun(int x){
    return (x%9 == 0) ? 9 : x%9;
}

bool ok = 0;
void dfs(int i, int l, int k, int b){
    if(ok) return;
    if(l == k && fun(i) == b){
        cout << i << "\n";
        ok = 1;
        return;
    }
    for(int d = i%10+1; d < 10; ++d){
        dfs(i*10+d, l+1, k, b);
    }
}

void solve(){
    int b, k;
    cin >> b >> k;
    dfs(0, 0, k, b);
    if(!ok) cout << -1 << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
