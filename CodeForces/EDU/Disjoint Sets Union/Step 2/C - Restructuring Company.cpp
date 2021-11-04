#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 2e5+5;

int p[N], nxt[N];

int find(int x){
    return p[x] < 0 ? x : p[x] = find(p[x]);
}

void uni(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    if(p[x] > p[y]) swap(x, y);
    p[y] = x;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    memset(p, -1, sizeof p);
    iota(nxt, nxt+N, 1);

    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i){
         int t, x, y;
         cin >> t >> x >> y;
         if(t == 1){ // union x, y
            uni(x, y);
         }
         else if(t == 2){
             int now = 0;
             for(x++; x <= y; x = now){
                uni(x-1, x);
                now = nxt[x];
                nxt[x] = nxt[y];
             }
         }
         else{
             x = find(x), y = find(y);
             cout << (x==y ? "YES\n" : "NO\n");
         }
    }

    return 0;
}
