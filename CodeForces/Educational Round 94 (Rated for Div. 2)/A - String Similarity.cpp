// Can be easy. but BF

#include <bits/stdc++.h>
#define Fast cin.tie(0), ios::sync_with_stdio(0)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long LL;
typedef pair<LL, LL> ii;
typedef vector<LL> vi;
const int N = 2*1e5 +5;
//const int lg = 20;
const LL mod = (LL)1e9+7;
LL n;
string str;
 
void primeArray(vi &arr){
    LL n = arr.size();
    for(int i = 0; i < n; ++i){
        cout << "index " << i << " [" << arr[i] << "]\n";
    }
}
 
void solve(){
    cin >> n >> str;
    string res = "";
    vector<string> arr;
    for(int i = 0; i < n; ++i){
        arr.push_back(str.substr(i, n));
    }
 
    for(int j = 0; j < n; ++j){
        int b = 1;
        for(int i = 0; i < arr.size(); ++i){
            b &= (arr[i][j]-'0');
        }
        res += (b+'0');
    }
 
    cout << res << "\n";
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
