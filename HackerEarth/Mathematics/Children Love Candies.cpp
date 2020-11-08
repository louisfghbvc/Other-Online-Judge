// O(t). Simple math

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL dfs(LL n, int t){
  if(!t) return n;
  if(n&1) n = n-(n+1)/2;
  else n = n-n/2;
  return dfs(n - n/4, t-1);
}

void solve(){
  LL n, t;
  cin >> n >> t;
  cout << dfs(n, t) << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
