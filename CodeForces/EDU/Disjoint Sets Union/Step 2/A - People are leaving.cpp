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

    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i){
        char c; int x;
        cin >> c >> x;

        if(c == '-'){
            p[x] = x+1; // connect to right
        }
        else{
            int right = find(x);
            if(right > n) right = -1;
            cout << right << "\n";
        }

    }

    return 0;
}
