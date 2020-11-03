// Monotonous. O(N).
// make increase array. when not, set 1.
// adjust decrease from back. 
// use dp concept but tricky.

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 1e5+5;

LL A[N];
LL sc[N];
int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> A[i];

  sc[0] = 1;
  for(int i = 1; i < n; ++i){
    if(A[i-1] < A[i]) sc[i] = sc[i-1]+1;
    else sc[i] = 1;
  }

  for(int i = n-2; i >= 0; --i){
    if(A[i] > A[i+1]) sc[i] = max(sc[i+1]+1, sc[i]);
  }

  LL res = 0;
  for(int i = 0; i < n; ++i)
    res += sc[i];
  cout << res << "\n";
}
