// Well, a observe.

#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int N = 1e5+5;
LL arr[N];
 
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> arr[i];
 
	LL res = 0;
	LL mn = 1e7;
	LL mx = -1;
	for(LL i = 1; i <= n; ++i){
		res += abs(arr[i]-i);
		mx = max(mx, min(i, arr[i]));
		mn = min(mn, max(i, arr[i]));
	}
 
	cout << res + max(0LL, 2LL*(mx-mn)) << "\n";
 
	return 0;
}
