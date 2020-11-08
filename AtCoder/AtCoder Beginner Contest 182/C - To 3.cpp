// N = 18. Backtracking. used or not used
// O(2^N). lazy. can faster.

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

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 2e5+5;

int l;
void dfs(vi &arr, int need, int cur, int i, int used){
    if(need == cur){
        l = min(used, l);
        return;
    }
    if(i >= sz(arr)) return;
    dfs(arr, need, cur, i+1, used);
    dfs(arr, need, (cur+arr[i])%3, i+1, used+1);
}

void solve(){
    l = 1e7;
    string s;
    cin >> s;
    vi arr;
    int sum = 0;
    for(char c: s){
        int cc = (c-'0')%3;
        if(cc) arr.push_back(cc);
        sum += cc;
    }
    sum %= 3;
    if(!sum){
        cout << 0 << "\n";
        return;
    }
    dfs(arr, sum, 0, 0, 0);
    if(l >= sz(s)){
        cout << -1 << "\n";
        return;
    }
    cout << l << "\n";
}
int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
