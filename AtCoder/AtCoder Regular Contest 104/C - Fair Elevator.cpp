// determine so many case. main idea is only care even segment.

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
 
const int N = 1e3+5;
 
void solve(){
    int n;
    cin >> n;
 
    vi A(n), B(n);
    for(int i = 0; i < n; ++i) cin >> A[i] >> B[i];
 
    int next[205] = {};
    int prev[205] = {};
    bool dp[205] = {};
 
    for(int i = 0; i < n; ++i){
        if(B[i] > 0 && A[i] >= B[i]){
            puts("No");
            return;
        }
        if(A[i] >= 1){
            if(next[A[i]] || prev[A[i]]){
                puts("No");
                return;
            }
        }
        if(B[i] >= 1){
            if(next[B[i]] || prev[B[i]]){
                puts("No");
                return;
            }
        }
        if(A[i] >= 1){
            next[A[i]] = B[i];
        }
        if(B[i] >= 1){
            prev[B[i]] = A[i];
        }
    }
 
    auto canPair = [&](int a, int b){
        if((prev[a] || next[b]) || (next[a] > 0 && next[a] != b)
           || (prev[b] > 0 && prev[b] != a) || (next[a] < 0 && prev[b] < 0))
           return false;
        return true;
    };
    
    dp[0] = true;
    for(int i = 2; i <= 2*n; i+=2){
        if(next[i]) continue;
        for(int j = i/2; j < i; ++j){
            if(!canPair(j, i)) continue;
            if(!dp[2*j-i]) continue; // care dp 0, 2, 4... must be true
 
            int d = i-j;
            bool fail = false;
            for(int l = i-1; l > j; --l){
                if(!canPair(l-d, l)){
                    fail = true;
                    break;
                }
            }
            if(!fail){
                dp[i] = true;
                break;
            }
        }
    }

    puts(dp[2*n] ? "Yes" : "No");
}
 
int main()
{
    Fast;
    //louisfghbvc
        solve();
    return 0;
}
