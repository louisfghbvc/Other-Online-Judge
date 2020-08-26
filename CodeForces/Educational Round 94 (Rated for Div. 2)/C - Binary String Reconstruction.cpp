// Use two pass, Because one pass may not good to handle condition.
// O(N).

#include <bits/stdc++.h>
 
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
//const int N = 2*1e5 +5;
//const int lg = 20;
//const LL mod = 1e9+7;
 
void primeArray(vi &arr){
    LL n = arr.size();
    for(int i = 0; i < n; ++i){
        cout << "index " << i << " [" << arr[i] << "]\n";
    }
}
 
string s;
LL x;
 
void solve(){
    cin >> s >> x;
    int n = s.size();
    string w = string(n, '1');
    for(int i = 0; i < n; ++i){
        if(s[i] == '0'){
            if(i+x < n) w[i+x] = '0';
            if(i >= x) w[i-x] = '0';
        }
    }
    for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
            if(i+x < n && w[i+x] == '1') continue;
            if(i >= x && w[i-x] == '1') continue;
            cout << "-1\n"; return;
        }
    }
    cout << w << "\n";
}
 
int main()
{
 
    Fast;
    int t;
    cin >> t;
    while(t--){
 
        solve();
 
    }
 
 
    return 0;
}
