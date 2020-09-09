// Two Pointer. O(N).
// If p[i]%p[j] > p[j]%p[i]. p[i] must be the ans.
// 2%3, 3%2 => 2, 1. 2 is origin.

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define SZ(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

int ask(int i, int j){
    cout << '?' << " " << i+1 << " " << j+1 << endl;
    int res;
    cin >> res;
    return res;
}

void solve(){
    int n;
    cin >> n;
    vi ans(n, -1);
    int l = 0, r = n-1;
    while(l < r){
        int a = ask(l, r), b = ask(r, l);
        if(a > b)
            ans[l++] = a;
        else
            ans[r--] = b;
    }
    ans[l] = n;
    cout << '!';
    for(int x : ans)
        cout << " " << x;
    cout << endl;
}

int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
