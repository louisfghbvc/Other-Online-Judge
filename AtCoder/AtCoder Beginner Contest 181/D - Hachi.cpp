// Number theory.
// use fre array.

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

void solve(){
    string s;
    cin >> s;

    int cnt[10] = {};
    for(char c: s) cnt[c-'0']++;

    int x = 8;
    while(x < 1000){
        int tag[10] = {};
        bool gg = 0;
        int tmp = x;
        while(tmp > 0){
            if(tmp%10 == 0) gg = 1;
            tag[tmp%10]++;
            tmp /= 10;
        }
        x += 8;
        if(gg) continue;
        bool ok = 1;
        if(x < 100){
            for(int i = 0; i < 10; ++i) ok &= tag[i] == cnt[i];
        }
        else{
            for(int i = 0; i < 10; ++i) ok &= tag[i] <= cnt[i];
        }
        if(ok){
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
