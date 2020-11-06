// So, just Enum all points.
#include <bits/stdc++.h>

using namespace std;

struct node{
  int x, y, r;
};

double dis(int x1, int y1, int x2, int y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
  int n;
  cin >> n;
  node arr[n];
  for(int i = 0; i < n; ++i){
    cin >> arr[i].x >> arr[i].y >> arr[i].r;
  }
  int res = 0;
  for(int i = 1; i <= 1000; ++i){
    for(int j = 1; j <= 1000; ++j){
      int cnt = 0;
      for(int k = 0; k < n; ++k){
        if(dis(i, j, arr[k].x, arr[k].y) <= arr[k].r) cnt++;
      }
      res += (cnt >= 2);
    }
  }
  cout << res << "\n";
}


