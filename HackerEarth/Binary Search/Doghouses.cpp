// Use prefix sum, cuz N = 1000.
// main idea is edge check. enumerate y.
// and check left and right has at least 1 x.

#include <bits/stdc++.h>
using namespace std;
#define MAX 1002
int cnt[MAX], L[MAX], R[MAX], cum[MAX][MAX];
 
int main()
{
  int n;
  cin >> n;
  for(int x = 1, y; x <= n; x++){
    cin >> y;
    y++;
    cum[x][y]++;
    cnt[y]++;
    R[y] = x;
    if(!L[y]) L[y] = x;
  }
  if(n <= 2){
    cout << n;
    return 0;
  }
  for(int x = 1; x < MAX; x++){
    for(int y = 1; y < MAX; y++){
      cum[x][y] += cum[x][y-1];
    }
  }
  for(int y = 1; y < MAX; y++){
    for(int x = 1; x < MAX; x++){
      cum[x][y] += cum[x-1][y];
    }
  }
  int res = 0;
  for(int i = 1; i < MAX; i++)
  {
    for(int j = i+1; j < MAX; j++)
    {
      int tem = cnt[i] + cnt[j];
      if(cnt[i] == 0 || cnt[j] == 0)
      {
        res = max(res, tem);
        continue;
      }
      int l = min(L[i], L[j]);
      int r = max(R[i], R[j]);
      tem += (cum[MAX-1][j] - cum[r][j] - cum[MAX-1][i] + cum[r][i]) > 0;
      tem += (cum[l-1][j] - cum[l-1][i]) > 0;
      res = max(res, tem);
    }
  }
  cout << res;
    return 0;
}

// BS.
