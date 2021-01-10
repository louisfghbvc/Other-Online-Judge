// Simulate.
// but autually only compute left, right part max, ==.
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
    int n;
    cin >> n;
    vi arr(1<<n);
    cin >> arr;

    vi win;
    for(int i = 0; i < 1<<n; ++i){
        win.push_back(i);
    }
    for(int i = 1; i < sz(arr); i *= 2){
        if(sz(win) == 2){
            int id;
            if(arr[win[0]] > arr[win[1]]) id = win[1];
            else id = win[0];
            cout << id+1 << "\n";
            return;
        }
        vi tmp;
        for(int k = 0; k+1 < sz(win); k+=2){
            int id;
            if(arr[win[k]] > arr[win[k+1]]) id = win[k];
            else id = win[k+1];
            tmp.push_back(id);
        }
        //cout << tmp << "\n";
        win = tmp;
    }

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
