// Just sort, careful some case.
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

void solve(){
    string s;
    cin >> s;
    sort(All(s), [&](char a, char b){
            bool ad = isdigit(a), bd = isdigit(b);
            if(ad && bd){
                a -='0'; b-='0';
                bool ao = a&1, bo = b&1;
                if(ao && bo){
                    return a < b;
                }
                if(!ao && !bo) return a < b;
                return ao;
            }
            if(!ad && !bd){
                a -= 'a', b -= 'a';
                bool ao = a&1, bo = b&1;
                if(ao && bo){
                    return a < b;
                }
                if(!ao && !bo) return a < b;
                return ao;
            }
            return !ad;
        });
    cout << s << "\n";
}

int main()
{
    Fast;
    louisfghbvc
        solve();
    return 0;
}
