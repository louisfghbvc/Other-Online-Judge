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
3
1 2
2 4
4 4

10
8 8
5 8
8 9
1 4
1 3
5 7
4 8
2 2
4 5
6 8

**/

struct node{
    int id, time, val;
    bool operator<(const node &n2) const{
        return time < n2.time || time == n2.time && val > n2.val;
    }
};


void solve(int n){
    cin >> n;

    vector<node> arr;
    
    for(int i = 0, l, r; i < n; i++){
        cin >> l >> r;
        arr.push_back({i, l, 1});
        arr.push_back({i, r, -1});
    }
    sort(All(arr));
    
    int res = 0;
    vector<int> room;
    vector<int> assign(n); // id to room

    int flow = 0;
    for(auto &x: arr){
        flow += x.val;
        res = max(flow, res);
        if(x.val < 0){ // leave
            room.push_back(assign[x.id]);
        }
        if(room.empty()){
            room.push_back(res);
        }
        if(x.val > 0){ // enter
            assign[x.id] = room.back();
            room.pop_back();
        }
    }

    cout << res << "\n";
    for(int i = 0; i < n; ++i){
        cout << assign[i] << " \n"[i==n-1];
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
