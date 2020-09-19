// Floyd Cycle.
// O(M).

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
 
const int N = 2e5+5;
 
void solve(){
    LL n, x, m;
    cin >> n >> x >> m;
    LL res = 0;
 
    LL slow = x, fast = x;
    do{
        slow = slow*slow%m;
        fast = fast*fast%m;
        fast = fast*fast%m;
    }while(slow != fast);
 
    fast = x;
    int L = 0;
    while(slow != fast){
        res += fast;
        L++;
        if(L == n){
            cout << res << "\n";
            return;
        }
        slow = slow*slow%m;
        fast = fast*fast%m;
    }
    n -= L;
 
    vi cyc;
    do{
        cyc.push_back(slow);
        slow = slow*slow%m;
    }while(slow != fast);
 
    LL cyclen = sz(cyc);
    for(int i = 0; i < cyclen; ++i){
        res += (n/cyclen)*cyc[i];
    }
    n %= cyclen;
    for(int i = 0; i < n; ++i){
        res += cyc[i];
    }
    cout << res << "\n";
}
 
int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
