// just Greedy as problem say.

#include <bits/stdc++.h>
 
#define Fast cin.tie(0), ios::sync_with_stdio(0)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 3*1e5 +5;
const int lg = 20;
LL n, m;
LL a[3], b[3];
 
void solve(){
    LL res = 2LL*min(a[2], b[1]);
    LL rem2 = (a[2]-b[1]>0) ? a[2]-b[1] : 0;
    LL brem2 = (rem2+a[0]>=b[2]) ? 0 : b[2]-(rem2+a[0]);
    if(brem2){
        res -= 2LL*min(a[1], brem2);
    }
    cout << res << "\n";
}
 
void req(){
 
}
 
int main()
{
 
    Fast;
    int t;
    cin >> t;
    while(t--){
        for(int i= 0; i< 3; ++i) cin >> a[i];
        for(int i= 0; i< 3; ++i) cin >> b[i];
 
        solve();
        req();
    }
 
 
    return 0;
}
