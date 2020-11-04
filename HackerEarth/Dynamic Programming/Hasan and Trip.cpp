// Like dijkstra. but not.
// just bottom up dp.
// how to get i, is from dp[j].
// O(N^2)

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

double dis(LL x1, LL y1, LL x2, LL y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
  int n;
  cin >> n;

  LL x[n], y[n], f[n];
  for(int i = 0; i < n; ++i)
    cin >> x[i] >> y[i] >> f[i];

  vector<double> dp(n+5, LLONG_MIN);
  dp[0] = f[0];
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < i; ++j){
      dp[i] = max(dp[i], dp[j] + f[i] - dis(x[i], y[i], x[j], y[j]));
    }
  }

  printf("%.6f\n", dp[n-1]);
}
