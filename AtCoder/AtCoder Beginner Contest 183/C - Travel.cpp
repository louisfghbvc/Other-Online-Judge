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
const int N = 105;

LL arr[N][N];

void solve(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> arr[i][j];

    vi ord(n-1);
    for(int i = 0; i+1 < n; ++i) ord[i] = i+1;
    int cnt = 0;
    do{
        LL w = arr[0][ord[0]] + arr[ord[n-2]][0];
        for(int i = 0; i+1 < sz(ord); ++i){
            w += arr[ord[i]][ord[i+1]];
        }
        if(w == k) cnt++;
    }while(next_permutation(All(ord)));

    cout << cnt << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
