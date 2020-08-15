// so Greedy can't work.
// use dp. all case enum. so dp[i][j][k] can from [i-1][j-1] or [i-1][k-1] or [j-1][k-1]. 3 direction
// remember sort first. so that the base will correct. because rgb need to use all.
// O(N^3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 200+5;
LL R[N], G[N], B[N];
LL dp[N][N][N];
 
int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    for(int i = 0; i < r; ++i) cin >> R[i];
    for(int i = 0; i < g; ++i) cin >> G[i];
    for(int i = 0; i < b; ++i) cin >> B[i];
 
    sort(R, R+r);
    sort(G, G+g);
    sort(B, B+b);
 
    for(int i = 0; i <= r; ++i){
        for(int j = 0; j <= g; ++j){
            for(int k = 0; k <= b; ++k){
                if(i&&j) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + R[i-1]*G[j-1]);
                if(j&&k) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + G[j-1]*B[k-1]);
                if(i&&k) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + R[i-1]*B[k-1]);
            }
        }
    }
 
    cout << dp[r][g][b] << endl;
 
    return 0;
}
