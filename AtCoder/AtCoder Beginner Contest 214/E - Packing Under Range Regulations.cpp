/**                                          
 __         ______     __  __     __     ______     ______   ______     __  __     ______     __   __   ______    
/\ \       /\  __ \   /\ \/\ \   /\ \   /\  ___\   /\  ___\ /\  ___\   /\ \_\ \   /\  == \   /\ \ / /  /\  ___\   
\ \ \____  \ \ \/\ \  \ \ \_\ \  \ \ \  \ \___  \  \ \  __\ \ \ \__ \  \ \  __ \  \ \  __<   \ \ \'/   \ \ \____  
 \ \_____\  \ \_____\  \ \_____\  \ \_\  \/\_____\  \ \_\    \ \_____\  \ \_\ \_\  \ \_____\  \ \__|    \ \_____\ 
  \/_____/   \/_____/   \/_____/   \/_/   \/_____/   \/_/     \/_____/   \/_/\/_/   \/_____/   \/_/      \/_____/                                       
**/
#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(All(x)); x.erase(unique(All(x)), x.end());
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/
 
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }
 
const int N = 2e5+5;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
/**
**/

map<int, int> p;
int find(int x){
    if(!p.count(x)) return p[x] = x;
    return p[x] == x ? x : p[x] = find(p[x]);
}
void uni(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    p[x] = y;
}

void solve(int T){
    int n;
    cin >> n;
    p.clear();
    vector<ii> arr(n);
    for(auto &it: arr){
        cin >> it.first >> it.second;
    }
    sort(All(arr), [&](ii &a, ii &b){
        return a.second < b.second || a.second == b.second && a.first < b.first;
    });

    for(auto &[l, r]: arr){
        // put deadline leftmost
        int now = find(l);
        if(now > r){
            cout << "No\n";
            return;
        }
        uni(now, now+1); // all l group assign to now+1
    }
    cout << "Yes\n";
}   
 
int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    louisfghbvc
        solve(1);
    return 0;
}

// Solution2 prefer. Greedy + heap. O(NlogN).
void solve(int T){
    int n;
    cin >> n;
    vector<ii> arr(n);
    map<int, vector<int>> events;
    for(auto &it: arr){
        cin >> it.first >> it.second;
        events[it.first].push_back(it.second);
    }
    
    priority_queue<int, vector<int>, greater<>> pq;
    auto i = events.begin();
    for(int x: i->second) pq.push(x);
    while(i != events.end()){
        int day = i->first;
        i++;
        int next_day = (i == events.end() ? INT_MAX : i->first);
        while(pq.size() && next_day > day){
            if(pq.top() < day){
                cout << "No\n";
                return;
            }
            pq.pop();
            day++;
        }
        if(i != events.end())
            for(int x: i->second)
                pq.push(x);
    }
    cout << "Yes\n";
}  
