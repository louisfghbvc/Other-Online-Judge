#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N = 1e5+5;
int fre[N];

void add(int x, int& nums){
    if(++fre[x] == 1) nums++;
}
void remove(int x, int& nums){
    if(--fre[x] == 0) nums--;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    LL n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    LL res = 0;
    int distinct_nums = 0;
    for(int r = 0, l = 0; r < n; ++r){
        add(arr[r], distinct_nums);
        while(distinct_nums > k){
            remove(arr[l], distinct_nums);
            l++;
        }
        res += r-l+1;
    }
    cout << res << "\n";
    
    return 0;
}
