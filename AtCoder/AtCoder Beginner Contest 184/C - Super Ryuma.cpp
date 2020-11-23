// Case. just 0-3.
// use parity is very tricky.

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
    LL a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == c && b == d){
        cout << 0 << "\n";
        return;
    }
    if(abs(a-c) + abs(b-d) <= 3 || a+b == c+d || a-b == c-d){
        cout << 1 << "\n";
        return;
    }
    if((a+b)%2 == (c+d)%2){
        cout << 2 << "\n";
        return;
    }

    for(int x = -3; x <= 3; ++x){
        for(int y = -3; y <= 3; ++y){
            if(abs(x) + abs(y) > 3) continue;
            LL X = a + x, Y = b + y;
            if(abs(X-c) + abs(Y-d) <= 3 || X+Y == c+d || X-Y == c-d){
                cout << 2 << "\n";
                return;
            }
        }
    }

    cout << 3 << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
