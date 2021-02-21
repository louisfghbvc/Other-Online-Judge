// calculate different number!!! I did not see that. simple.

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

const int N = 2e3+5;
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully
**/

void solve(){
    string x;
    LL m;
    cin >> x >> m;
    int d = (*max_element(All(x))) - '0';
    LL l = d+1, r = LLONG_MAX;
    while(l < r){
        LL base = l + (r-l)/2;
        bool ok = 1;
        __int128 t = 0;
        for(char c: x){
            t = t*base + c-'0';
            if(t > m){
                ok = 0;
                break;
            }
        }
        if(ok) l = base+1;
        else r = base;
    }
    if(sz(x) == 1 && l - d - 1){
        cout << 1 << "\n";
        return;
    }
    cout << l - d - 1 << "\n";
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
