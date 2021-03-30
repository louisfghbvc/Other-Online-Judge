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

const int N = 305;
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully
**/

void solve(){
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    --x, --y;
    vector<string> arr(h);
    cin >> arr;
    int cnt = 0;
    for(int j = y; j >= 0; --j){
        if(arr[x][j] == '#') break;
        else cnt++;
    }
    for(int j = y+1; j < w; ++j){
        if(arr[x][j] == '#') break;
        else cnt++;
    }

    for(int i = x-1; i >= 0; --i){
        if(arr[i][y] == '#') break;
        else cnt++;
    }
    for(int i = x+1; i < h; ++i){
        if(arr[i][y] == '#') break;
        else cnt++;
    }

    cout << cnt << "\n";
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
