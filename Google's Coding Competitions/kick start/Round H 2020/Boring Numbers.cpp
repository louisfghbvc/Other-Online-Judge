// Digit dp. similiar with Leetcode problems.
// each will 5 possible.
// O(logn)

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

const int N = 100+5;

int cas = 1;

LL ans(LL tmp){
    string x = to_string(tmp);
    int l = sz(x);
    LL res = 0;
    for(int i = 1; i < l; ++i)
        res += pow(5, i);

    for(int i = 0; i < l; ++i){
        int id = i+1;
        bool same = 0;
        if(id & 1){
            for(char d: {'1', '3', '5', '7', '9'}){
                if(d < x[i]){
                    res += pow(5, l - 1 - i);
                }
                else if(d == x[i]) same = 1;
            }
        }
        else{
            for(char d: {'0', '2', '4', '6', '8'}){
                if(d < x[i]){
                    res += pow(5, l - 1 - i);
                }
                else if(d == x[i]) same = 1;
            }
        }
        if(!same) return res;
    }

    return res+1;
}

void solve(){
    cout << "Case #" << cas++ << ": ";
    LL l, r;
    cin >> l >> r;
    cout << ans(r) - ans(l-1) << "\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}

