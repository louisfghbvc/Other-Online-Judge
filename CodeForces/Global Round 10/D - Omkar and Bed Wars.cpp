// Observe. when LLL and RRR need to talk
// O(N).
// and the array is cycle.
// so first cut cycle to line. so check begin() and back().
// when all same (n+2)/3. think RRRRR
// or not all same but cut cycle. add a stop '$'
// check the sub-length. each sub-len/3 is ans.
// ex LLL can be RLL or LRL or LLR. 3 case. but no need to simulate.
// just calculate min case. ex RLLLLL => RLLRLL so 1. but can be RLRLLRL is 2. so mid is not optimal. no need to simulate.

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 2*1e5 +5;
//LL arr[N];
 
int main()
{
    LL t, n;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        int cnt = 0;
        int res = 0;
        while(s.size() && s[0] == s.back()){
            cnt++;
            s.pop_back();
        }
        if(s.empty()){
            res = ((n+2)/3);
        }
        else{
            s += '$';
            for(int i = 0; i+1 < s.size(); ++i){
                cnt++;
                if(s[i] != s[i+1]){
                    res += cnt/3;
                    cnt = 0;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}
