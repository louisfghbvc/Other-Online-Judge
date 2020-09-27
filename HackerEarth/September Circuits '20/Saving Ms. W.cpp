// Very good problem, dp + dijkstra.
// the map is dp[u][stamina] min sleep, also stamina is 1e9, but all possible is fine.
// and get min sleep. 

#include <bits/stdc++.h>
using namespace std;
 
void dbg_out() { cout << " end.\n"; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
 
typedef long long LL;
typedef pair<LL, LL> ii;
const int N = 1e3+5;
 
vector<ii> g[N];
ii stm[N];
map<LL, LL> mp[N];
 
int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
 
	for(int i = 0; i < m; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		g[x].push_back({y, z});
		g[y].push_back({x, z});
	}
 
	for(int i = 1; i <= n; ++i){
		cin >> stm[i].first >> stm[i].second;
	}
	
	priority_queue<pair<LL, ii>> pq;
	pq.push({0, {a, 0}});
	while(pq.size()){
		auto t = pq.top(); pq.pop();
		LL d = -t.first;
		LL u = t.second.first;
		LL stamina = t.second.second;
		if(u == b){
			cout << d << "\n";
			return 0;
		}
		bool useless = false;
		for(auto &it: mp[u]){
			if(stamina <= it.first && it.second <= d) useless = true;
		}
		if(useless) continue;
		mp[u][stamina] = d;
		pq.push({-d-stm[u].second, {u, stm[u].first}});
		for(auto &[v, vw]: g[u]){
			if(stamina >= vw)
				pq.push({-d, {v, stamina-vw}});
		}
	}
 
	cout << -1 << "\n";
}
