// Enum all prefix and suffix..
// O(N). doesn't know why if condition in Enum will WA.

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
 
const int N = 2e5+5;
 
void solve(){
    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;
 
    vi lmx(n, LLONG_MIN);
    vi lmn(n, LLONG_MAX);
    vi rmx(n, LLONG_MIN);
    vi rmn(n, LLONG_MAX);
 
    LL mx = arr[0], mn = arr[0];
    for(int i = 1; i < n; ++i){
        if(arr[i] >= 0){
            lmx[i] = max(arr[i] * mx, lmx[i-1]);
            lmn[i] = min(arr[i] * mn, lmn[i-1]);
        }
        else{
            lmx[i] = max(arr[i] * mn, lmx[i-1]);
            lmn[i] = min(arr[i] * mx, lmn[i-1]);
        }
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
 
    mx = arr[n-1], mn = arr[n-1];
    for(int i = n-2; i >= 0; --i){
        if(arr[i] >= 0){
            rmx[i] = max(arr[i] * mx, rmx[i+1]);
            rmn[i] = min(arr[i] * mn, rmn[i+1]);
        }
        else{
            rmx[i] = max(arr[i] * mn, rmx[i+1]);
            rmn[i] = min(arr[i] * mx, rmn[i+1]);
        }
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
 
    mx = LLONG_MIN;
    for(int i = 2; i+2 < n; ++i){
 
        mx = max(mx, lmx[i-1]*arr[i]*rmx[i+1]);
        mx = max(mx, lmn[i-1]*arr[i]*rmn[i+1]);
 
        mx = max(mx, lmx[i-1]*arr[i]*rmn[i+1]);
        mx = max(mx, lmn[i-1]*arr[i]*rmx[i+1]);
 
    }
 
    cout << mx << "\n";
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}

// O(NlogN). sort first. because the five number always i<j<k<l<t.
// pick five. Greedy.
// Just 3 case. 0 neg, 2 neg, 4neg.
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
 
const int N = 2e5+5;
 
void solve(){
    int n;
    cin >> n;
    vi arr(n);
    cin >> arr;
 
    sort(All(arr));
    LL mx = LLONG_MIN;
    mx = max(mx, arr[n-1]*arr[n-2]*arr[n-3]*arr[n-4]*arr[n-5]);
    mx = max(mx, arr[n-1]*arr[n-2]*arr[n-3]*arr[0]*arr[1]);
    mx = max(mx, arr[n-1]*arr[0]*arr[1]*arr[2]*arr[3]);
    cout << mx << "\n";
}
 
int main()
{
    Fast;
    louisfghbvc{
        solve();
    }
    return 0;
}
