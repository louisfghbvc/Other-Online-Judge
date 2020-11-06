// =_= math.
// Jacobi four square theorem
// for m in [1, n]. m|n. and 4 not |m.
// final mul 8.

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void solve(){
  LL n;
  cin >> n;
  LL res = 0;
  for(LL i = 1; i <= sqrt(n); ++i){
    if(n%i == 0){
      if(i%4) res += i;
      if(i != n/i && (n/i)%4) res += n/i;
    }
  }
  cout << res*8 << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
