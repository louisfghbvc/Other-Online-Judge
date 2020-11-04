// bad description...
// just odd even. and make row+col to one value.

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve(){
  int n;
  LL x, y, z;
  cin >> n;
  vector<int> f[2];
  for(int i = 0; i < n; ++i){
    cin >> x >> y >> z;
    f[(x+y)%2].push_back(z&1);
  }
  int ok1 = 1, ok2 = 1, ok3 = 1, ok4 = 1;
  for(auto it : f[0]){
    ok1 &= (it == 0);
    ok2 &= (it == 1); 
  }
  for(auto it : f[1]){
    ok3 &= (it == 0);
    ok4 &= (it == 1); 
  }
  if((ok1 && ok4) || (ok2 && ok3))
    cout<<"Yes\n";
  else
    cout<<"No\n";
}

int main(){
  int t;
  cin >> t;
  while(t--) solve();        		
}
