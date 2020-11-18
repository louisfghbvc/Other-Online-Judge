// Enum all 2x2 case. mess.

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

struct node{
    int a, b, c, d, e, f;
};

vector<node> res;
string arr[105];
void pattern(int i, int j){
    if(arr[i][j] == '1' && arr[i][j+1] == '1' && arr[i+1][j] == '1' && arr[i+1][j+1] == '1'){
        arr[i][j] = arr[i+1][j] = arr[i+1][j+1] = '0';
        res.push_back({i+1, j+1, i+2, j+1, i+2, j+2});
        return;
    }
    if(arr[i][j] == '1' && arr[i][j+1] == '0' && arr[i+1][j] == '0' && arr[i+1][j+1] == '0'){
        arr[i][j] = '0'; arr[i+1][j] = arr[i][j+1] = '1';
        res.push_back({i+1, j+1, i+2, j+1, i+1, j+2});
        return;
    }
    if(arr[i][j] == '0' && arr[i][j+1] == '1' && arr[i+1][j] == '0' && arr[i+1][j+1] == '0'){
        arr[i][j+1] = '0'; arr[i+1][j] = arr[i+1][j+1] = '1';
        res.push_back({i+1, j+2, i+2, j+1, i+2, j+2});
        return;
    }
    if(arr[i][j] == '0' && arr[i][j+1] == '0' && arr[i+1][j] == '1' && arr[i+1][j+1] == '0'){
        arr[i+1][j] = '0'; arr[i][j] = arr[i+1][j+1] = '1';
        res.push_back({i+2, j+1, i+1, j+1, i+2, j+2});
        return;
    }
    if(arr[i][j] == '0' && arr[i][j+1] == '0' && arr[i+1][j] == '0' && arr[i+1][j+1] == '1'){
        arr[i+1][j+1] = '0'; arr[i+1][j] = arr[i][j+1] = '1';
        res.push_back({i+2, j+2, i+2, j+1, i+1, j+2});
        return;
    }
    if(arr[i][j] == '1' && arr[i][j+1] == '0' && arr[i+1][j] == '0' && arr[i+1][j+1] == '1'){
        arr[i][j] = '0'; arr[i+1][j] = arr[i][j+1] = '1';
        res.push_back({i+1, j+1, i+2, j+1, i+1, j+2});
        return;
    }
    if(arr[i][j] == '0' && arr[i][j+1] == '1' && arr[i+1][j] == '1' && arr[i+1][j+1] == '0'){
        arr[i][j+1] = '0'; arr[i][j] = arr[i+1][j+1] = '1';
        res.push_back({i+1, j+2, i+1, j+1, i+2, j+2});
        return;
    }
    if(arr[i][j] == '1' && arr[i][j+1] == '1' && arr[i+1][j] == '1' && arr[i+1][j+1] == '0'){
        arr[i][j] = arr[i][j+1] = arr[i+1][j] = '0';
        res.push_back({i+1, j+1, i+1, j+2, i+2, j+1});
        return;
    }
    if(arr[i][j] == '0' && arr[i][j+1] == '1' && arr[i+1][j] == '1' && arr[i+1][j+1] == '1'){
        arr[i][j+1] = arr[i+1][j] = arr[i+1][j+1] = '0';
        res.push_back({i+1, j+2, i+2, j+1, i+2, j+2});
        return;
    }
    if(arr[i][j] == '1' && arr[i][j+1] == '0' && arr[i+1][j] == '1' && arr[i+1][j+1] == '1'){
        arr[i+1][j] = arr[i][j] = arr[i+1][j+1] = '0';
        res.push_back({i+2, j+1, i+1, j+1, i+2, j+2});
        return;
    }
    if(arr[i][j] == '1' && arr[i][j+1] == '1' && arr[i+1][j] == '0' && arr[i+1][j+1] == '1'){
        arr[i][j] = arr[i][j+1] = arr[i+1][j+1] = '0';
        res.push_back({i+1, j+1, i+1, j+2, i+2, j+2});
        return;
    }
    if(arr[i][j] == '1' && arr[i][j+1] == '1' && arr[i+1][j] == '0' && arr[i+1][j+1] == '0'){
        arr[i+1][j] = arr[i+1][j+1] = '1'; arr[i][j] = '0';
        res.push_back({i+2, j+1, i+2, j+2, i+1, j+1});
        return;
    }
    if(arr[i][j] == '0' && arr[i][j+1] == '1' && arr[i+1][j] == '0' && arr[i+1][j+1] == '1'){
        arr[i][j] = arr[i+1][j] = '1'; arr[i+1][j+1] = '0';
        res.push_back({i+1, j+1, i+2, j+1, i+2, j+2});
        return;
    }
    if(arr[i][j] == '0' && arr[i][j+1] == '0' && arr[i+1][j] == '1' && arr[i+1][j+1] == '1'){
        arr[i][j] = arr[i][j+1] = '1'; arr[i+1][j] = '0';
        res.push_back({i+1, j+1, i+1, j+2, i+2, j+1});
        return;
    }
    if(arr[i][j] == '1' && arr[i][j+1] == '0' && arr[i+1][j] == '1' && arr[i+1][j+1] == '0'){
        arr[i][j+1] = arr[i+1][j+1] = '1'; arr[i][j] = '0';
        res.push_back({i+1, j+2, i+2, j+2, i+1, j+1});
        return;
    }
}

void solve(){
    res.clear();
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    for(int i = 0; i+1 < n; ++i){
        for(int j = 0; j+1 < m; ++j){
            while(true){
                if(arr[i][j] == '0' && arr[i][j+1] == '0' && arr[i+1][j] == '0'
               && arr[i+1][j+1] == '0') break;
               pattern(i, j);
            }
        }
    }
    cout << sz(res)<< "\n";
    for(int i = 0; i < res.size(); ++i){
        cout << res[i].a << " " << res[i].b << " " << res[i].c << " " << res[i].d << " " << res[i].e << " " << res[i].f << "\n";
    }
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
