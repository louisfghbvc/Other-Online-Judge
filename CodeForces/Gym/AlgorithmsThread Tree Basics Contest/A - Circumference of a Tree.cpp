// so the main idea is find diameter of a tree. then multiply 3
// so random node dfs, and dfs again. now find farest maxd. and calculate
// O(M)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 3*1e5 +5;
//LL arr[N];
vector<int> g[N];
int mx = 0, mxd = 0;
 
void dfs(int u, int d = 0, int p = -1){
    if(mxd < d){
        mx = u;
        mxd = d;
    }
    for(int &v: g[u]){
        if(v == p) continue;
        dfs(v, d+1, u);
    }
}
 
void solve(){
    dfs(0);
    mxd = 0;
    dfs(mx);
    cout << 3*mxd << endl;
}
 
int main()
{
    LL n, a, b;
    cin >> n;
    for(int i = 0; i < n-1; ++i){
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    solve();
 
    return 0;
}
