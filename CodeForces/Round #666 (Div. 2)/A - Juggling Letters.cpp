// the idea is really simple. 
// so the string can remove a char. and put to other string that char.
// make all strings equal. so easily can check all lowercase char frequency % n == 0 (note: n is the number of all strings)
// O(N).

#include <bits/stdc++.h>
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
//const int N = 2*1e5 +5;
//const int lg = 20;
//const LL mod = 1e9+7;
 
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
void solve(){
    int n;
    cin >> n;
    vector<string> arr(n+2);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    int fre[26] = {};
    for(string &s: arr)
        for(char &c: s)
            fre[c-'a']++;
    bool ok = 1;
    for(int i = 0; i < 26; ++i){
        if(fre[i] && fre[i] % n != 0){
            ok = 0;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
