// convert time and nothing, just easy.
// O(N).

#include <bits/stdc++.h>

using namespace std;

struct Tmer{
  int from, to;
};

int helper(string s){
  int h = (s[0]-'0')*10 + (s[1]-'0');
  int m = (s[3]-'0')*10 + (s[4]-'0');
  return h*60+m; 
}

int solve(){
  int n;
  cin >> n;

  string a, b, c;
  int r, s, wake, finaltime, store;
  cin >> a >> b >> c >> r >> s;

  finaltime = helper(a);
  wake = helper(b), store = helper(c);

  wake = max(wake, store - r);

  if(n == 0) return -1;
  Tmer arr[n];
  for(int i = 0; i < n; ++i){
    cin >> a >> b;
    arr[i].from = helper(a);
    arr[i].to = helper(b);
  }

  int mustgo = 2*r+s;
  int mn = 1e9, mni = -1;

  for(int i = 0; i < n; ++i){
    if(wake + mustgo < arr[i].from && wake + mustgo < finaltime){
      if(mni == -1 || wake + mustgo < mn){
        mn = wake + mustgo;
        mni = i+1;
      }
    }
    else if(max(arr[i].to, wake) + mustgo < finaltime){
      int takes = max(arr[i].to, wake) + mustgo;
      if (takes < mn) {
        mn = takes;
        mni = i+1;
      }
    }
  }

  return mni;
}

int main() {
  int t, cas = 1;
  cin >> t;
  while(t--){
    printf("Case %d: %d\n", cas++, solve());
  }
  return 0;
}

