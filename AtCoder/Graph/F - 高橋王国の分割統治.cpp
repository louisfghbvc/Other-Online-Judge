// Just Tree Graph, and the small must upper than bigger number, that is the problem say.
// so from n-1 to 0
// d means num of node(include self) 
// and mx means maximum connected commponet. means childs biggest or n - i's nums of node
// O(N).

#include <bits/stdc++.h>
#define N 100005
using namespace std;

int d[N], mx[N];
vector<int> g[N];

int main()
{
    int n, x;
    while(cin >> n){
        for(int i = 0; i < n; ++i) g[i].clear();
        memset(d, 0, sizeof d);
        memset(mx, 0, sizeof mx);
        for(int i = 1; i <= n-1; ++i){
            cin >> x;
            g[x].push_back(i);
        }
        for(int u = n-1; u >= 0; --u){
            d[u] = 1;
            for(auto &v : g[u]){
                d[u] += d[v];
                mx[u] = max(mx[u], d[v]);
            }
            mx[u] = max(mx[u], n-d[u]);
        }

        for(int i= 0; i < n; ++i){
            cout << mx[i] << endl;
        }

    }
}
/**
5
0
1
1
0
**/
