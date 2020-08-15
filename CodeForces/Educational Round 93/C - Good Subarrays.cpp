// O(N). prefix tweak.
// so the question is count subarray sum == subarray length
// Pr - Pl == r - l,
// so Pr - r = Pl - l. so map the Pl-l. and calculate Pr-r
// Next time I will done.QQ

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
 
int main()
{
    int t, n;
    cin >> t;
    string s;
    while(t--){
        cin >> n >> s;
        unordered_map<int, int> mp;
        mp[0]++;
        LL sum = 0, res = 0;
        for(int i = 0; i < n; ++i){
            sum += s[i]-'0';
            res += mp[sum-(i+1)];
            mp[sum-(i+1)]++;
        }
        cout << res << endl;
    }
}
