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
    LL res = 0;
    for(int r = 0, l = 0; r < n; ++r){
        sum += arr[r];
        while(sum > s){
            sum -= arr[l];
            l++;
        }
        res += r-l+1;
    }

    cout << res << "\n";

    return 0;
}
