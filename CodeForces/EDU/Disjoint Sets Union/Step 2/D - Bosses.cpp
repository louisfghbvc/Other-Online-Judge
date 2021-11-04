#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 3e5+5;

int p[N], dis[N];

int find(int x){
    if(p[x] < 0) return x;
    int root = find(p[x]);
    dis[x] += dis[p[x]];
    return p[x] = root;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    memset(p, -1, sizeof p);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
         int t;
         cin >> t;
         if(t == 1){ // a -> b
             int a, b;
             cin >> a >> b;
             dis[a] = dis[b]+1;
             p[a] = b;
         }
         else{
            int c;
            cin >> c;
            find(c);
            cout << dis[c] << "\n";
         }
    }

    return 0;
}
