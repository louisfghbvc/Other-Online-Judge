// use prime to determine the gcd is duplicate.
// O(N).

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
 
const int N = 1e6+5;
bool np[N];
vi prime;
 
void init(){
    for(int i = 2; i <= sqrt(N); ++i){
        if(!np[i]){
            prime.push_back(i);
            for(int j = i+i; j < N; j+=i)
                np[j] = 1;
        }
    }
}
 
void solve(){
    init();
 
    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;
 
    LL g = arr[0];
    for(int i = 1; i < n; ++i) g = __gcd(g, arr[i]);
    if(g != 1){
        cout << "not coprime\n";
        return;
    }
 
    unordered_set<LL> st;
    for(int i = 0; i < n; ++i){
        LL t = arr[i];
        for(int j = 0; j < sz(prime); ++j){
            LL px = prime[j];
            if(px > t) break;
            bool f = 0;
            while(t%px == 0){
                t /= px;
                f = 1;
            }
            if(f){
                if(st.count(px)){
                    cout << "setwise coprime\n";
                    return;
                }
                st.insert(px);
            }
        }
        if(t != 1){
            if(st.count(t)){
                cout << "setwise coprime\n";
                return;
            }
            st.insert(t);
        }
    }
 
    cout << "pairwise coprime\n";
}
 
int main()
{
    Fast;
    //louisfghbvc{
        solve();
    //}
    return 0;
}
