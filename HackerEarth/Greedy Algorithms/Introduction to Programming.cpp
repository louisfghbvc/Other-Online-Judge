// O(N). =_= WA. almost done...
// maintain the seq increasing order. 
// so that is smallest. think about 3 2 1, k = 1. so when 32 -> X2. and next 1->21. smallest

#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int k;

  cin >> s >> k;
  int len = s.size();

  string res = "";
  for(int i = 0; i < len; ++i){
    while(res.size() && res.back() > s[i] && k){
      --k;
      res.pop_back();
    }
    if(res.size() == 1 && res[0] == '0') res.pop_back();
    res += s[i];
  }
  while(k > 0 && res.size()) res.pop_back();
  if(res.empty()) res = "0";
  cout << res << "\n";
}
