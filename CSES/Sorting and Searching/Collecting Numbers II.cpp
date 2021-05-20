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

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
5 3
4 2 1 5 3
2 3
1 5
2 3

4 2 1 5 3
3

4 1 2 5 3
2

3 1 2 5 4
3

3 2 1 5 4
4

**/

int arr[N];
int pos[N];
void solve(int n){
    int m;
    cin >> n >> m;
    
    for(int i = 1; i <= n;++i){
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int res = 1;
    for(int i = 1; i+1 <= n; ++i){
        if(pos[i] > pos[i+1]) res++;
    }

    auto op = [&](int p, int p1, int np, int np1) -> void{
        if(p <= p1 && np > np1) res++;
        if(p > p1 && np <= np1) res--;
    };

    for(int i = 0, l, r; i < m; ++i){
        cin >> l >> r;
        int l_val = arr[l], r_val = arr[r];
        swap(arr[l], arr[r]);

        op(pos[l_val-1], pos[l_val], pos[l_val-1], r);
        op(pos[l_val], pos[l_val+1], r, pos[l_val+1]);
        pos[l_val] = r;

        op(pos[r_val-1], pos[r_val], pos[r_val-1], l);
        op(pos[r_val], pos[r_val+1], l, pos[r_val+1]);
        pos[r_val] = l;

        cout << res << "\n";
    }
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
