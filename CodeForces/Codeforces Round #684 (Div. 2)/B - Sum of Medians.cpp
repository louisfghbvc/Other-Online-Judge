// Greedy. just put big first.

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

int dd(int a, int b){
    return (a+b-1)/b;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vi arr(n*k);
    cin >> arr;

    int mid = dd(n, 2)-1;
    int idx = n-mid-1;
    priority_queue<int> pq(All(arr));
    LL res = 0, cnt = 0, tot = 0;
    while(pq.size()){
        int x = pq.top(); pq.pop();
        if(cnt == idx){
            res += x;
            tot++;
            if(tot == k) break;
            cnt = 0;
        }
        else cnt++;
    }
    cout << res << "\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
