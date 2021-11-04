#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 1e6+5;

int p[N];

int find(int x){
    return p[x] < 0 ? x : p[x] = find(p[x]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    memset(p, -1, sizeof p);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;

        int right = find(x);
        cout << right << " ";
        int nxt = right%n+1;
        p[right] = find(nxt);
    }

    return 0;
}
