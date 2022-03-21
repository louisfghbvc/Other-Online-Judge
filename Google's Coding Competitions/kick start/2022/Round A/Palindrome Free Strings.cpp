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
// template <class T> using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/
 
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << H << ' '; dbg_out(T...); }
 
const int N = 123456+5;
const LL INF = 1e13;
const int mod = 1e9+7;
const LL MXP = 1e10;
/**
**/

bool isPalindrome(const string &s) {
    for (int i = 0; i < s.size()/2; ++i) {
        if (s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

void solve(int T) {
    cout << "Case #" << T+1 << ": ";
    int n;
    cin >> n;
    string s;
    cin >> s;

    // base case
    if (n <= 4) {
        cout << "POSSIBLE\n";
        return;
    }

    // string palindrome length can not more than 5

    // from left -> right use a set to record all state
    // when a new letter in, just eliminate the palindrome state
    // check the state is palidrome or add a digit producce a palindrome length 6

    set<string> st; 
    st.insert("");
    for (int i = 0; i < 5; ++i) {
        set<string> nst; 
        for (auto &c: st) {
            if (s[i] == '?') {
                nst.insert(c + "0");
                nst.insert(c + "1");
            } 
            else {
                nst.insert(c + s[i]);
            }
        }
        st = nst;
    }

    // check if have self palindrome
    set<string> nst;
    for (auto &c: st) {
        if (!isPalindrome(c)) 
            nst.emplace(c);
    }
    st = nst;

    auto valid = [&](string &c) {
        if (!isPalindrome(c)) { // length 6
            c.erase(c.begin());
            if (!isPalindrome(c)) // length 5
                return true;
        }
        return false;
    };

    for (int i = 5; i < n; ++i) {
        nst.clear();
        for (auto &c: st) {
            if (s[i] == '?') {
                string t = c + "0";
                if (valid(t))
                    nst.emplace(t);
                t = c + "1";
                if (valid(t))
                    nst.emplace(t);
            } 
            else {
                string t = c + s[i];
                if (valid(t))
                    nst.emplace(t);
            }
        }
        st = nst;
    }

    if (st.size()) cout << "POSSIBLE\n";
    else cout << "IMPOSSIBLE\n";
}   

int main(){
    Fast;
    // freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
    louisfghbvc
        solve(tt);
    return 0;
}
