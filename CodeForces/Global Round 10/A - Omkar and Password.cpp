// Just check if all same.
// all same n, or 1
// different nums merge different. 

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
        int x = arr[0];
        bool same = 1;
        for(int i = 1; i < n; ++i){
            if(x != arr[i]) same = false;
        }
        if(same) cout << n << endl;
        else puts("1");
    }
    return 0;
}
