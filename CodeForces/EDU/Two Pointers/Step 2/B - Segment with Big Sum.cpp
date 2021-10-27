#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    LL n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    LL sum = 0;
    int res = n+1; // can use all - sum at most k segment
    for(int r = 0, l = 0; r < n; ++r){
        sum += arr[r];
        while(sum >= s){
            res = min(res, r-l+1);
            sum -= arr[l];
            l++;
        }
    }

    cout << (res == n+1 ? -1 : res) << "\n";

    return 0;
}
