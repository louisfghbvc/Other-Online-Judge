// O(N!a*b)
// just Brute Force.

#include <bits/stdc++.h>
using namespace std;

string mix(string a, string b){
  int i;
  for(i = 0; i < a.size(); ++i){
    string sa = a.substr(i);
    if(sa.size() > b.size()) continue;
    string sb = b.substr(0, sa.size());
    if(sa == sb) break;
  }
  for(int j = a.size()-i; j < b.size(); ++j)
    a += b[j];
  return a;
}

int main() {
  int n, ans = 0;

  cin >> n;
  vector<string> arr(n);
  vector<int> ord(n);
  for(int i = 0; i < n; ++i){
    ord[i] = i;
    cin >> arr[i];
    ans += arr[i].size();
  }

  do{
    string tmp = arr[ord[0]];
    for(int i = 1; i < n; ++i)
      tmp = mix(tmp, arr[ord[i]]);
    ans = min(ans, (int)tmp.size());
  }while(next_permutation(ord.begin(), ord.end()));

  cout << ans << "\n";
}

