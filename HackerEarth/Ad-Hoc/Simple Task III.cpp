// use just two char... think as 3 char...
// O(1).

#include <bits/stdc++.h>

using namespace std;

int dfs(int arr[3]){
  if(arr[1] < arr[2]) return 2*arr[1]+1;
  return arr[1]+arr[2];
}

void solve(){
  int arr[3];
  for(int i = 0; i < 3; ++i) cin >> arr[i];
  sort(arr, arr+3);
  cout << dfs(arr) << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}



