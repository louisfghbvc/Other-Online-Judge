// Just a special case k = 1. if all array are all same.
// otherwise can always make m arrays. because increase. not notice this. so gg.
// So just implement if diff num = k. then after that index, all substract the prev.

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
    int n, k;
    cin >> n >> k;
    vi arr(n);
    cin >> arr;

    int m = 0;
    if(k == 1){
        m = 1;
        for(int i = 1; i < n && m != -1; ++i)
            if(arr[i] != arr[i-1]) m = -1;
    }
    else{
        for(m = 0; arr.back() != 0; ++m){
            int prev = -1;
            for(int i = 0, j = k; i < n; ++i){
                if(prev != arr[i]){
                    if(j > 0) prev = arr[i], j--;
                }
                arr[i] -= prev;
            }
        }
    }

    cout << m << "\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
