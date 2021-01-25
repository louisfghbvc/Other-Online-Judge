// WA 15 times. fucking floating point use eps. or just use multiply.

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

const int N = 3e5+5;
const int mod = 1e9+7;


void solve(){
    LL n, x;
    cin >> n >> x;

    double vol = 0;
    int id = -1;
    for(int i = 0; i < n; ++i){
        double v, p;
        cin >> v >> p;
        double tmp = v * p / 100.0;
        vol += tmp;
        if(vol-x > 1e-9){
            if(id < 0) id = i+1;
        }
        //cout << vol << "\n";
    }

    cout << id << "\n";

}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}

/**
enjoy the problem.
**/
