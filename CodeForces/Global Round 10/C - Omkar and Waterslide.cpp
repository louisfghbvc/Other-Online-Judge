// Find max length. like brick wall.
// max can cover small. so add descending diff.
// O(N).

#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 2*1e5 +5;
int arr[N];
 
int main()
{
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i= 0; i < n; ++i) cin >> arr[i];
        LL res = 0;
        for(int i = 1; i < n; ++i){
            if(arr[i-1] > arr[i])
                res += (arr[i-1]-arr[i]);
        }
        cout << res << endl;
    }
    return 0;
}
