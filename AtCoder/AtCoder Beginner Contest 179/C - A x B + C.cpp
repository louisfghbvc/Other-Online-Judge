// Find factor numbers.
// O(sqrt(N)loglog(N))

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
 
const int N = 1e6+5;
vector<int> p;
bool np[N];
 
void init(){
    for(int i = 2; i <= sqrt(N); ++i){
        if(!np[i]){
            p.push_back(i);
            for(int j = 2*i; j < N; j+=i)
                np[j] = 1;
        }
    }
}
 
LL gg(int x){
    LL res = 1;
    for(int &prime: p){
        if(prime > x) break;
        LL c = 0;
        while(x%prime == 0){
            x /= prime;
            c++;
        }
        res *= (c+1);
    }
    if(x != 1) res *= 2;
    return res;
}
 
void solve(){
    init();
    int n;
    cin >> n;
    LL res = 0;
    for(int c = 1; c < n; ++c){
        int ab = n-c;
        res += gg(ab);
    }
    cout << res << "\n";
}
 
int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
