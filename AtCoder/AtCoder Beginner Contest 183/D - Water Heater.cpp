// Classic array tour.

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

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int mod = 1e9+7;
const int N = 2e5+5;

void solve(){
    LL n, w;
    cin >> n >> w;
    vi fre(N);
    for(int i = 0; i < n; ++i){
        int s, t, p;
        cin >> s >> t >> p;
        fre[s] += p;
        fre[t] -= p;
    }

    LL sum = 0;
    for(int i = 0; i < N; ++i){
        sum += fre[i];
        if(sum > w){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
