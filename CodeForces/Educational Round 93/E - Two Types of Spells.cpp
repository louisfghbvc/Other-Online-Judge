// Very good problem. O(NlogN).
// maintain a datastructure.
// use 4 set. when x > 0, add to ans. otherwise substract to ans and delete.
// so each time move fire and light smallest from double to normal. need move 2 times ? No. bacause each turn enter 1 spell.
// and calculate the light can double times. total - used.
// and the double light must have one in normal. bacause the light change the next.
// so grab maximum from fire or light normal. move to double.

// Good problems...

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 2*1e5 +5;
//LL arr[N];
 
LL n;
set<LL> sp[2][2]; // first dim -fire or light, second dim -double or not
LL ans = 0;
 
void upd(int t){
    if(sp[t][1].size() > 0){
        auto v = sp[t][1].begin();
        ans -= *v;
        sp[t][0].insert(*v);
        sp[t][1].erase(v);
    }
}
 
void solve(){
    cin >> n;
    LL x, t;
 
    for(int i = 0; i < n; ++i){
        cin >> t >> x;
        if(x < 0){
            x = -x;
            if(sp[t][0].count(x)){
                sp[t][0].erase(x);
                ans -= x;
            }
            else{
                sp[t][1].erase(x);
                ans -= 2*x;
            }
        }
        else{
            ans += x;
            sp[t][0].insert(x);
        }
        
        upd(0); // move fire smallest double to normal. must regret machine
        upd(1); // move light smallest double to normal. must regret
 
        LL ndoubled = sp[0][1].size() + sp[1][1].size();
        LL nlight = sp[1][0].size() + sp[1][1].size();
        LL req = nlight - ndoubled;
        while(req > 0 && (sp[0][0].size() > 0 || sp[1][0].size() > 1 )){
            int tar = 0;
            if(sp[0][0].size() == 0) tar = 1;
            else if(sp[1][0].size() == 1) tar = 0;
            else{
                tar = *sp[0][0].rbegin() > *sp[1][0].rbegin() ? 0 : 1;
            }
            auto v = sp[tar][0].rbegin();
            ans += *v;
            sp[tar][1].insert(*v);
            sp[tar][0].erase(*v);
            req--;
        }
        cout << ans << "\n";
    }
}
 
int main()
{
    solve();
    return 0;
}
