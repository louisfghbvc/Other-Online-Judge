#include <bits/stdc++.h>

#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define All(x) x.begin(), x.end()
#define louisfghbvc int t; cin >> t; for(int tt = 0; tt < t; ++tt)
#define sz(x) (int)(x).size()
#define sort_unique(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()));
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;

template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(auto &it : v) is >> it; return is; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep = ""; for(const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

const int N = 5e3 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
/**
Read problem statement carefully
ababc
4
ab
abab
c
cb  
**/

struct trie{
    trie* next[26] = {};
    bool isW = false;
};

string s;
trie *root = new trie();
LL dp[N];

void insert(string &t){
    trie *tmp = root;
    for(char c: t){
        if(!tmp->next[c-'a']) tmp->next[c-'a'] = new trie();
        tmp = tmp->next[c-'a'];
    }
    tmp->isW = true;
}

LL search(int i){
    LL res = 0;
    trie* tmp = root;
    for(int j = i; j < sz(s); ++j){
        if(!tmp->next[s[j] - 'a']) return res;
        tmp = tmp->next[s[j] - 'a'];
        if(tmp->isW){
            res += dp[j+1];
            res %= mod;
        }
    }
    return res;
}

void solve(int k){
    cin >> s;
    cin >> k;
    for(int i = 0; i < k; ++i){
        string t;
        cin >> t;
        insert(t);
    }
    dp[sz(s)] = 1;
    for(int i = sz(s) - 1; i >= 0; --i){
        dp[i] = search(i);
    }
    cout << dp[0] << "\n";
}

int main()
{
    Fast;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // louisfghbvc
        solve(1);
    return 0;
}

/**
Enjoy the problem.
**/
