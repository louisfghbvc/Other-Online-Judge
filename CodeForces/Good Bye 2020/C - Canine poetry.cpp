// O(N). So just check 2 or 3 is palindrome or not. and marked it.
// Prove. each i can have 4 neighbors. and we have 26 char. just like colored problems.
// So i just different colors by 4 neighbors [i-2, i+2].

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

const int N = 1e2+5;

void solve(){
    string s;
    cin >> s;

    vector<bool> used(sz(s));
    int res = 0;

    for(int i = 1; i < sz(s); ++i){
        bool g = 0;
        if(s[i] == s[i-1] && !used[i-1]) g = 1;
        if(i > 1 && s[i] == s[i-2] && !used[i-2]) g = 1;
        used[i] = g;
        res += used[i];
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
