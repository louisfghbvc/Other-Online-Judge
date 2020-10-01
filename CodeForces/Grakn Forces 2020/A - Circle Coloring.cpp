// Just implement, just check last maybe.
// other just ai or bi. here use general solution.

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<int> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 3e5+5;

void solve(){
    int n;
    cin >> n;
    int arr[n][3];
    for(int k = 0; k < 3; ++k)
        for(int i = 0; i < n; i++)
            cin >> arr[i][k];
    vi ans(n);

    for(int i = 0; i < n; ++i){
        if(i){
            for(int j = 0; j < 3; ++j)
                if(arr[i][j] != ans[i-1] && arr[i][j] != ans[(i+1)%n]){
                    ans[i] = arr[i][j];
                    break;
                }
        }
        else ans[i] = arr[i][0];
    }

    for(int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i==n-1];
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
