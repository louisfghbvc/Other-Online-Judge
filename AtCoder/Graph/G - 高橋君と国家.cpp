// minimum spanning tree tweak, because it can state it self, so connect it to zero point.
// O(ElogE)

#include <bits/stdc++.h>
#define N 100005
using namespace std;

struct edge{
    int a, b, c;
    bool operator<(const edge &e2){
        return c < e2.c;
    }
};

int p[N];
int find(int x){
    return p[x] < 0 ? x : p[x] = find(p[x]);
}

int main()
{
    int n, m, c;
    while(cin >> n >> m){
        memset(p, -1, sizeof p);
        vector<edge> e;
        for(int i = 1; i <= n; ++i){
            cin >> c;
            e.push_back({0, i, c});
        }
        for(int i = 0; i < m; ++i){
            int a, b;
            cin >> a >> b >> c;
            e.push_back({a, b, c});
        }
        sort(e.begin(), e.end());
        long long int ans = 0;
        for(int i = 0; i < e.size(); ++i){
            int a = find(e[i].a), b = find(e[i].b);
            if(a == b) continue;
            p[b] = a;
            ans += e[i].c;
        }

        cout << ans << endl;
    }
}
/**
7 8
40
50
30
70
70
80
80
1 2 40
1 3 50
1 4 60
2 5 90
3 4 80
4 5 110
5 6 60
6 7 50
**/
