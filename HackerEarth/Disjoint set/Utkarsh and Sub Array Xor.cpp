// Don't understand problem statement...
// Convert S[u] XOR... S[v] to prefix[u-1] XOR prefix[v].
// if add edge ans = ans/2.

#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
typedef long long LL;
LL fpow(LL a, LL b){
  LL res = 1;
  while(b){
    if(b&1) res = res*a%mod;
    a = a*a%mod;
    b >>= 1;
  }
  return res;
}

unordered_map<LL, LL> p;
LL find(int x){
  if(!p.count(x) || p[x] == x) return p[x] = x;
  return p[x] = find(p[x]);
}

int main() {
  LL n, k;
  cin >> n >> k;
  LL res = fpow(2, n);
  for(int i = 0; i < k; ++i){
    LL u, v;
    cin >> u >> v;
    --u;
    u = find(u), v = find(v);
    if(u != v){
      p[v] = u;
      res = res * fpow(2, mod-2) % mod;
    }
    cout << res << "\n";
  }
}
