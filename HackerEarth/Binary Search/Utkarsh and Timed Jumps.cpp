// use math formula, easy to check that always can do at most n
// overflow issue use int128.
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve(){
  LL n;
  cin >> n;
  LL ans = n;
  LL l = 1, r = n;
  while(l <= r){
    LL mid = l + (r-l) / 2;
    if((__int128)(mid+1)*mid/2 >= n) ans = mid, r = mid-1;
    else l = mid+1; 
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}

