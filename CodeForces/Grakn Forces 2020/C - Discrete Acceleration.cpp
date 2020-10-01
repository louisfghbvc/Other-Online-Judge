// just implement. use index of flag.
// so two cars calculate which is close to the flag. and compute time.
// just simulate. 

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
    int n, l;
    cin >> n >> l;
    vector<double> arr(n);
    cin >> arr;

    double lpos = 0.0, lspeed = 1.0, rpos = l, rspeed = 1.0;
    double time = 0;

    int lp = 0, rp = n-1;
    while(lp <= rp){
        double lf = arr[lp] - lpos;
        double rf = rpos - arr[rp];
        double ltime = lf/lspeed, rtime = rf/rspeed;
        if(ltime < rtime){
            lpos = arr[lp];
            time += ltime;
            rpos -= ltime*rspeed;
            lspeed++;
            lp++;
        }
        else{
            rpos = arr[rp];
            time += rtime;
            lpos += rtime*lspeed;
            rspeed++;
            rp--;
        }
    }
    time += (rpos-lpos)/(lspeed+rspeed);
    printf("%.10f\n", time);
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
