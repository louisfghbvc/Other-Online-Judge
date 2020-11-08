// array tour. O(N).
// update query once.
// sort and pair. Greedy.
// O(NlogN).

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int main() {
  int n, q;
  cin >> n >> q;

  vector<int> arr(n);
  for(int i = 0; i < n; ++i) cin >> arr[i];
  sort(arr.rbegin(), arr.rend());

  int l, r;
  vector<int> fre(n);
  while(q--){
    cin >> l >> r;
    --l, --r;
    fre[l]++;
    fre[r+1]--;
  }

  for(int i = 1; i < n; ++i)
    fre[i] += fre[i-1];
  sort(fre.rbegin(), fre.rend());

  LL ans = 0;
  for(int i = 0; i < n; ++i)
    ans += (long)fre[i]*arr[i];
  cout << ans << "\n";
}
