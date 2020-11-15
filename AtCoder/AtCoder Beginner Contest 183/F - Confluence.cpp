// OMG. just implement... Not so hard.
// Union find + unordered_map. map record class number.

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
int p[N];
unordered_map<int, int> gp[N];

int find(int x){
    return p[x] == x ? x : p[x] = find(p[x]);
}

void solve(){
    int n, q, c, x, y;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        p[i] = i;
        cin >> c;
        gp[i][c]++;
    }
    while(q--){
        cin >> c >> x >> y;
        if(c == 1){
            x = find(x), y = find(y);
            if(x == y) continue;
            if(sz(gp[x]) < sz(gp[y])) swap(x, y);
            p[y] = x;
            for(auto &i: gp[y]){
                gp[x][i.first] += i.second;
            }
        }
        else{
            cout << gp[find(x)][y] << "\n";
        }
    }

}

int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
