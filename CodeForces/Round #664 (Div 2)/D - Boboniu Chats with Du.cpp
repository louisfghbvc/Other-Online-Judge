// so the key point is max the value.
// so when pick big. if will occur d+1 days.
// but if u put big in the last, it can just 1 days.
// why is (i-1)*(d+1) + 1 ? only 1 big. the day is 1.
// and two big. the day is 1 + (d+1).
// .... big.size(). the day is 1 + (d+1)*size.
// careful day can't > n. the total length.

// so try to enum all case.
// big = 0, 1....  small pre[n-0], pre[n-1]...
// OMG. this not so hard.. QQ

// O(NlogN). Greedy + enum

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
LL n, d, m, x;
 
int main()
{
    cin >> n >> d >> m;
    vi big, small;
    for(int i = 0; i < n; ++i){
        cin >> x;
        if(x > m) big.push_back(x);
        else small.push_back(x);
    }
    sort(big.rbegin(), big.rend());
    sort(small.rbegin(), small.rend());
 
    int k1 = big.size(), k2 = small.size();
    LL pre[k2+1];
    pre[0] = 0;
 
    for(int i = 0; i < k2; ++i) pre[i+1] = pre[i] + small[i];
 
    LL ans = pre[k2], sum = 0;
    for(LL i = 1; i <= k1 && (i-1)*(d+1)+1 <= n; ++i){
        sum += big[i-1];
        int rem = n - max(0LL, (i-1)*(d+1)+1);
        ans = max(ans, sum + pre[min(rem, k2)]);
    }
 
    cout << ans << endl;
    return 0;
}
