// bfs use diameter, O(N). stable the dfs dp cuz dp may not be the diameter node. so need other check
// if WA many times try bfs. don't stick with one method.

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<pair<int, int>> g[N];
int dis[N];
bool vis[N];
int n;

int bfs(int u){
  queue<int> q;
  q.push(u);

  memset(vis, 0, sizeof vis);
  memset(dis, 0, sizeof dis);
  vis[u] = 1;
  while(q.size()){
    u = q.front(); q.pop();
    for(auto &[v, cost]: g[u]){
      if(!vis[v]){
        vis[v] = 1;
        dis[v] = dis[u] + cost;
        q.push(v);
      }
    } 
  }
  return max_element(dis+1, dis+n+1)-dis;
}

void solve(){
  cin >> n;
  for(int i = 1; i <= n; ++i) g[i].clear();

  for(int i = 1; i < n; ++i){
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }

  int st = bfs(1);
  int p = bfs(st);
  int ans = dis[p];
  int cost = 0;
  if(ans > 10000) cost = 10000;
  else if(ans > 1000) cost = 1000;
  else if(ans > 100) cost = 100;

  cout << cost << " " << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) 
    solve();
}

