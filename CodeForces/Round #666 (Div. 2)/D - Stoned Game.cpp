// just simulate.
// observe that each player choose the biggest pile. so that make other lose.
// and use a priority_queue to simulate.
// and maintain a buffer to record the previous take. because can not take same pile than prev player.
// the number is small. so that is ok.

#include <bits/stdc++.h>
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
void solve(){
    int n;
    cin >> n;
    vi arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    priority_queue<LL> pq(All(arr));
    bool T = 1;
    vi pre;
    while(pq.size()+pre.size() > 0){
        if(pq.size()+pre.size() == 1){
            puts( T ? "T" : "HL");
            return;
        }
        LL tmp = pq.top(); pq.pop();
        if(pre.size()) pq.push(pre[0]), pre.clear();
        if(--tmp) pre.push_back(tmp);
        T ^= 1;
    }
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
