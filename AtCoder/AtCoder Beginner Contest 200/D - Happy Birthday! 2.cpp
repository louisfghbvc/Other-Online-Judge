// O(N200). 

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 2e2+5;
const int INF = 0x3f3f3f3f;
/**
Read problem statement carefully

**/

void solve(LL n){
    cin >> n;
    vi arr(n);
    cin >> arr;

    vector<int> pos[200];
    for(int i = 0; i < 200; ++i) pos[i].clear();

    map<int, vector<int>> sum;
    for(int i = 0; i < n; ++i){
        arr[i] %= 200;
        map<int, vector<int>> nxt = sum;
        for(auto &[k, v]: sum){
            v.push_back(i);
            int nk = (k + arr[i])%200;
            if(nxt.count(nk)){
                cout << "YES\n";
                cout << sz(nxt[nk]);
                for(auto &val: nxt[nk])
                    cout << " " << val+1;
                cout << "\n";

                cout << sz(v);
                for(auto &val: v)
                    cout << " " << val+1;
                cout << "\n";
                return;
            }
            nxt[nk] = v;
        }
        if(nxt.count(arr[i])){
            cout << "YES\n";
            cout << sz(nxt[arr[i]]);
            for(auto &val: nxt[arr[i]])
                cout << " " << val+1;
            cout << "\n";

            cout << 1;
            cout << " " << i+1;
            cout << "\n";
            return;
        }
        nxt[arr[i]].push_back(i);
        sum = nxt;
    }
 
    cout << "NO\n";
}

int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;

}

/**
Enjoy the problem.
**/
