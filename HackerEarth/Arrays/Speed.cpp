// Simple monotonous.
// O(N). just maintain a stack.

#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n;
  cin >> n;
  int arr[n];
  for(int i= n-1; i >= 0; --i) cin >> arr[i];

  stack<int> car;
  for(int i = 0; i < n; ++i){
    while(car.size() && car.top() > arr[i]) car.pop();
    car.push(arr[i]);
  }
  cout << car.size() << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}

