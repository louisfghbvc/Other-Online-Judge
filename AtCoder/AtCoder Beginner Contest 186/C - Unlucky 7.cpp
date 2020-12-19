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
const int N = 3e5+5;

bool oc(int x){
    while(x){
        if(x%8==7) return false;
        x/=8;
    }
    return true;
}

bool dc(int x){
    while(x){
        if(x%10==7) return false;
        x/=10;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    int cnt= 0;
    for(int i = 1; i <= n; ++i){
        if(oc(i) && dc(i)) cnt++;
    }
    cout << cnt << "\n";
}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
