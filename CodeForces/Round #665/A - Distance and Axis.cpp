// Math. So the main idea is parity.
// O(1). if k is same parity as n. and k < n. so (n-k)%2.
// otherwise k-n.

#include <bits/stdc++.h>
 
#define Fast cin.tie(0), ios::sync_with_stdio(0)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 3*1e5 +5;
const int lg = 20;
LL n, k;
 
void solve(){
 
}
 
void req(){
 
}
 
void read(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int ans = 0;
        if(n % 2 == 0){
            if(k <= n && k % 2 == 0) ans = 0;
            else if(k <= n && k % 2 == 1) ans = 1;
            else ans = abs(n-k);
        }
        else{
            if(k <= n && k % 2 == 1) ans = 0;
            else if(k <= n && k % 2 == 0) ans = 1;
            else ans = abs(n-k);
        }
        cout << ans << "\n";
    }
}
 
int main()
{
 
    Fast;
    read();
    solve();
    req();
 
    return 0;
}
