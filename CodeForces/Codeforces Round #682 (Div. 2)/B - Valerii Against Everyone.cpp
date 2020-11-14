// Sad. so easy. just check pair is same. cuz 2^k can't sum to 2^n if distinct.
// So check duplicate...

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

const int N = 1500+5;


void solve(){
    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;

    unordered_map<int, int> mp;
    for(int x: arr) mp[x]++;
    for(auto &[a, b]: mp){
        if(b >= 2){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
