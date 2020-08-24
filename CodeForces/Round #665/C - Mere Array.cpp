// Just sort and check if can be divisible by min_element.
// O(NlogN)

#include <bits/stdc++.h>
 
#define Fast cin.tie(0), ios::sync_with_stdio(0)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 2*1e5 +5;
const int lg = 20;
LL n;
vector<LL> arr;
 
void solve(){
    vector<LL> tmp = arr;
    sort(tmp.begin(), tmp.end());
    bool ok = 1;
    for(int i = 0; i < n; ++i){
        if(tmp[i] % tmp[0] != 0 && tmp[i] != arr[i]){
            ok = 0;
            break;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}
 
void req(){
 
}
 
int main()
{
 
    Fast;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        arr.clear();
        arr.resize(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
 
        solve();
        req();
    }
 
 
    return 0;
}
