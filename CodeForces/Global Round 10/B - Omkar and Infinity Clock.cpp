// Cycle length is 2
// why? because max is curr max, and min will be next max.
// and max will be next next max. Simple to observe

#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 2*1e5 +5;
LL arr[N];
 
int main()
{
    LL t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        LL mx = INT_MIN;
        for(int i = 0; i < n; ++i) cin >> arr[i], mx = max(arr[i], mx);
        if(k % 2){
            for(int i = 0; i < n; ++i){
                arr[i] = mx - arr[i];
            }
        }
        else{
            LL nmx = INT_MIN;
            for(int i = 0; i < n; ++i){
                arr[i] = mx - arr[i];
                nmx = max(nmx, arr[i]);
            }
            for(int i = 0; i < n; ++i){
                arr[i] = nmx - arr[i];
            }
        }
        cout << arr[0];
        for(int i = 1; i < n; ++i){
            cout <<  " " << arr[i];
        }
        cout << "\n";
    }
    return 0;
}
