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

const int N = 1e7+5;
const int inf = 0x3f3f3f3f;
/**
Read problem statement carefully

**/

inline void no(){
    cout << "UNSOLVABLE\n";
}

int use[26];
string a, b, c;
bool flag = false;
void dfs(int vis, int i, string g){
    //dbg_out(vis, i, g);
    if(flag) return;
    if(i >= sz(g)){
        string l = g.substr(0, sz(a));
        string r = g.substr(sz(a), sz(b));
        string tot = g.substr(sz(a) + sz(b), sz(c));
        if(l[0] != '0' && r[0] != '0' && tot[0] != '0'){
            if(stoll(l) + stoll(r) == stoll(tot)){
                cout << l << "\n" << r << "\n" << tot << "\n";
                flag = 1;
            }
        }
        return;
    }

    char pre = g[i];
    int id = g[i]-'a';
    if(use[id] >= 0){
        g[i] = '0' + use[id];
        dfs(vis, i+1, g);
        g[i] = pre;
        return;
    }

    for(int d = 0; d <= 9; ++d){
        if(vis>>d&1) continue;
        //cout << "used " << d << "\n";
        use[id] = d;
        g[i] = '0' + use[id];
        dfs(vis | (1<<d), i+1, g);
        g[i] = pre;
        use[id] = -1;
    }

}

void solve(){
    memset(use, -1, sizeof use);

    cin >> a >> b >> c;
    set<char> st;
    for(char x: a) st.insert(x);
    for(char x: b) st.insert(x);
    for(char x: c) st.insert(x);
    if(sz(st) > 10){
        no();
        return;
    }
    dfs(0, 0, a+b+c);
    if(!flag)
        no();
}

int main()
{

    //Fast;
    //louisfghbvc
        solve();
    return 0;
}

/**
Enjoy the problem.
**/
