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

const int N = 105;
const int mod = 1e9+7;
/**
Read problem statement carefully
**/

int dg[N];
int arr[N];
int n;
void dfs(int l, int r, int dep){
    if(l > r) return;
    int mx = arr[l], id = l;
    for(int i = l; i <= r; ++i){
        if(arr[i] > mx){
            id = i;
            mx = arr[i];
        }
    }
    dg[mx] = dep;
    dfs(l, id-1, dep+1);
    dfs(id+1, r, dep+1);
}

void solve(){
    memset(dg, -1, sizeof dg);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    dfs(0, n-1, 0);
    for(int i = 0; i < n; ++i){
        cout << dg[arr[i]] << " \n"[i==n-1];
    }
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
