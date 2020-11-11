// O(N^2).
// just sort and insert.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> arr;
  string s;
  for(int i = 0; i < n; ++i){
    cin >> s;
    if(arr.empty()){
      cout << 0 << "\n";
      arr.push_back(s);
      continue;
    }
    auto p = lower_bound(arr.begin(), arr.end(), s);
    cout << p - arr.begin() << "\n";
    arr.insert(p, s);
  }
}

