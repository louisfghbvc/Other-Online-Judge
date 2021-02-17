// Reminder only can move to next. so just simulate.

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

const int N = 1e6+5;
const int mod = 1e9+7;
/**
Read problem statement carefully
1
9
7 1 3 4 2 10 3 9 6
**/

void solve(){
    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;
    int cnt[3] = {};
    for(int x: arr) cnt[x%3]++;
    int b = n/3, mov = 0;
    while(cnt[0] != cnt[1] || cnt[1] != cnt[2]){
        if(cnt[2] > cnt[0]){
            cnt[2]--;
            cnt[0]++;
        }
        else if(cnt[1] > cnt[2]){
            cnt[1]--;
            cnt[2]++;
        }
        else if(cnt[0] > cnt[1]){
            cnt[0]--;
            cnt[1]++;
        }
        else break;
        mov++;
    }
    cout << mov << "\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}

/**
enjoy the problem.
**/
