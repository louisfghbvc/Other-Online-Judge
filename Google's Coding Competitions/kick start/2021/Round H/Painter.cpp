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
/*
**/

// count continous segment
int segment(string &s){
    int res = 0;
    for(int i = 0, j ; i < s.size(); i = j){
        j = i;
        if(s[i] == '1') res++;
        while(j < s.size() && s[j] == s[i]) j++;
    }
    return res;
}

void solve(int T){
    printf("Case #%d: ", ++T);

    int n;
    cin >> n;
    string s;
    cin >> s;

    // Y B G
    int res = 0;
    // convert to Y
    string t = s;
    for(char &c: t){
        if(c == 'G' || c == 'Y' || c == 'A' || c == 'O') c = '1';
        else c = '0';
    }
    res += segment(t);
    t = s;
    // convert to R
    for(char &c: t){
        if(c == 'O' || c == 'R' || c == 'A' || c == 'P') c = '1';
        else c = '0';
    }
    res += segment(t);
    t = s;
    // convert to B
    for(char &c: t){
        if(c == 'G' || c == 'B' || c == 'P' || c == 'A') c = '1';
        else c = '0';
    }
    res += segment(t);
    cout << res << "\n";
}   
 
int main()
{
    // Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    louisfghbvc
        solve(tt);
    return 0;
}
