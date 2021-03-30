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
3
1 5 7
**/



void solve(){
    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;

    LL mn = INT_MAX;
    for(int mask = 0; mask < 1<<(n-1); ++mask){
        vi pos = {0, n};
        for(int b = n-2, k = 1; b >= 0; --b, ++k){
            if(mask>>b&1) pos.push_back(k);
        }
        sort(All(pos));
        LL cur_xor = 0;
        for(int i = 0; i+1 < sz(pos); ++i){
            int cur_or = 0;
            for(int j = pos[i]; j < pos[i+1]; ++j){
                cur_or |= arr[j];
            }
            cur_xor ^= cur_or;
        }
        mn = min(mn, cur_xor);
    }

    cout << mn << "\n";
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
