// So the main idea is count the path use cnt.
// can use dfs. use time = sb*(n-sb).
// and root 0 as no use. because only path not node.
// think: 1-2-3-4.
// and prime factor just combine last merge. because if sperate in each is not the maximal. easy to think.
// if not enough add 1.
// notice the mod. the biggest still be the biggest but mod make it small. watch out this.
// O(NlogN)

#include <bits/stdc++.h>
 
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 2*1e5 +5;
//const int lg = 20;
const LL mod = (LL)1e9+7;
LL n, m;
vi g[N];
vi prime;
LL sb[N];
LL edge[N];
 
void primeArray(vi &arr){
    LL n = arr.size();
    for(int i = 0; i < n; ++i){
        cout << "index " << i << " [" << arr[i] << "]\n";
    }
}
 
void dfs(LL u = 0, LL p = -1){
    sb[u] = 1;
    for(LL &v: g[u]){
        if(v != p){
            dfs(v, u);
            sb[u] += sb[v];
        }
    }
}
 
void solve(){
    n--;
    vi val(n, 1);
    while(m < n) prime.push_back(1), m++;
    sort(all(prime));
    while(m > n){
        LL t = prime.back();
        prime.pop_back();
        prime.back() = prime.back()*t%mod;
        m--;
    }
    for(int i = m-1; i >= 0; --i){
        val[i] = val[i] * prime[i];
    }
 
    //primeArray(val);
 
    dfs();
    for(int i = 1; i <= n; ++i){
        //cout << i <<" subtree number " << sb[i];
        LL time = sb[i]*((n+1)-sb[i]);
        //cout << " count " << time << "\n";
        edge[i-1] = time;
    }
    sort(edge, edge+n);
 
    LL res = 0;
    for(int i = 0; i < n; ++i){
        //cout << edge[i] << " pair " << val[i] << "\n";
        res = (res + edge[i] * val[i] % mod) % mod;
    }
 
    cout << res << "\n";
}
 
int main()
{
 
    Fast;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i) g[i].clear();
        memset(sb, 0, sizeof sb);
 
        int a, b;
        for(int i = 0; i < n-1; ++i){
            cin >> a >> b;
            --a, --b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
 
        cin >> m;
        prime.clear();
        prime.resize(m);
        
        for(int i = 0; i < m; ++i) cin >> prime[i];
        solve();
    }
    return 0;
}
