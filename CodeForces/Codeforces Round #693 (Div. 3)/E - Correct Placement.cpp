// Sort, and record minimum. like rolling prefix.
// O(NlogN).

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

const int N = 2e5+5;
const int mod = 1e9+7;
typedef array<int, 3> ar;

void solve(){
    int n;
    cin >> n;

    vector<ar> arr;
    for(int i = 0, h, w; i < n; ++i){
        cin >> h >> w;
        if(h > w) swap(h, w);
        arr.push_back({h, w, i});
    }

    sort(All(arr));

    vi res(n, -1);
    int best = 1e9, best_i = -1;
    for(int i = 0, j; i < n; i = j){
        for(j = i; j < n && arr[j][0] == arr[i][0]; j++){
            if(best < arr[j][1]){
                res[arr[j][2]] = best_i;
            }
        }
        for(j = i; j < n && arr[j][0] == arr[i][0]; j++){
            if(best > arr[j][1]){
                best = arr[j][1];
                best_i = arr[j][2]+1;
            }
        }
    }

    for(int i = 0; i < n; ++i)
        cout << res[i] << " \n"[i==n-1];
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
