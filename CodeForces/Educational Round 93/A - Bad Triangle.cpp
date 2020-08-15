// O(1).
// just check can be bad triangle or not.
// so check smallest and biggest. WA 1 time.QQ

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
 
int main()
{
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vi arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        if(arr[0] + arr[1] <= arr.back()){
            printf("%d %d %d\n", 1, 2, n);
        }
        else puts("-1");
 
    }
    return 0;
}
