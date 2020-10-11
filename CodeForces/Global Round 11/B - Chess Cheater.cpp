// Wow... math formula. greedy.
// so want to minimum the win segment.
// record loss segment, sort from small.
// O(NlogN). 
// check some edge case.

#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; while(t--)
#define sz(x) (int)(x).size()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<int> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << "\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int mod = 1e9+7;
const int N = 2e3+5;

void solve(){
    int k, n;
    cin >> n >> k;
    string s;
    cin >> s;

    int win = 0, loss = 0;
    int winT = 0;
    vi lossT;
    for(int i = 0; i < n; ++i){
        if(s[i] == 'W'){
            win++;
            if(!i || s[i-1] == 'L') winT++;
        }
        if(s[i] == 'L'){
            loss++;
            if(!i || s[i-1] == 'W') lossT.push_back(0);
            lossT.back()++;
        }
    }
    if(k >= loss){
        cout << 2*n-1 << "\n";
        return;
    }
    if(!win){
        if(k == 0) cout << 0 << "\n";
        else cout << 2*k-1 << "\n";
        return;
    }
    if(s[0] == 'L') lossT[0] = 1e8;
    if(s[n-1] == 'L') lossT.back() = 1e8;
    sort(All(lossT));
    win += k;
    for(int ls: lossT){
        if(ls > k) break;
        k -= ls;
        winT--;
    }
    cout << 2*win - winT << "\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
