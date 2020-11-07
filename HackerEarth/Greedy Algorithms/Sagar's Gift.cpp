// Greedy. just count the bit.

#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n;
  cin >> n;
  vector<int> arr(n);
  for(auto &it: arr) cin >> it;

  int cnt[10] = {};
  for(int x: arr){
    if(!x) cnt[x]++;
    while(x > 0){
      cnt[x%10]++;
      x/=10;
    }
  }

  for(int i = 9; i >= 0; --i)
    for(int k = 0; k < cnt[i]; ++k)
      cout << i;
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
