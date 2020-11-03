// maximum and is from b-1, b or b-2, b-1.
// enough b-2 is less one bit. and largest.

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

void solve(){
    LL a, b;
    cin >> a >> b;
    LL mx = 0;
    for(LL i = max(b-5, a); i < b; ++i){
        mx = max(mx, i&(i+1));
    }
    cout << mx << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
