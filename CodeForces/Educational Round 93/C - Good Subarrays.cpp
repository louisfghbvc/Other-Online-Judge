// O(N). prefix tweak.
// so the question is count subarray sum == subarray length
// Pr - Pl == len. so add Pr-len = Pl. and only check biggest length is enough.
// no need to from big to small length. because is covered.
// Next time I will done.

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
