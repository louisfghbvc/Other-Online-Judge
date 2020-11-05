// Sad fail.
#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
 
const int N = sqrt(1e9) + 5;
bool np[N];
vector<LL> p;
void init(){
  for(int i = 2; i < N; ++i){
    if(!np[i]){
      p.push_back(i);
      for(int j = i*2; j < N; j+=i)
        np[j] = 1;
    }
  }
}
 
LL foo(LL n){
  if(n <= 1) return n;
  LL res = n;
  for(LL x: p){
    if(x > n) break;
    if(n % x == 0) res -= res/x;
    while(n % x == 0) n /= x;
  }
  if(n > 1) res -= res/n;
  return res;
}
 
LL Sum(LL n){
  LL res = 0;
  for(LL i = 1; i <= sqrt(n); ++i){
    if(n%i == 0){
      res += foo(i);
      if((n/i) != i) res += foo(n/i);
    }
  }
  return res;
}
 
void solve(){
  LL n;
  cin >> n;
  cout << Sum(n) << "\n";
}
 
int main() {
  init();
  int t;
  cin >> t;
  while(t--) solve();
}


// observe that just O(1). cout << n
