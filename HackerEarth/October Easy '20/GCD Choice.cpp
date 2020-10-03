// Prefix and Suffix.
// remove each i, and count gcd(pre[i-1], suf[i+1]).
// O(N).

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int arr[N], pre[N], suf[N];

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> arr[i];

	pre[0] = arr[0];
	for(int i = 1; i < n; ++i){
		pre[i] = __gcd(pre[i-1], arr[i]);
	}

	suf[n-1] = arr[n-1];
	for(int i = n-2; i >= 0; --i){
		suf[i] = __gcd(suf[i+1], arr[i]);
	}

	int res = 0;
	for(int i = 0; i < n; ++i){
		if(i == 0) res = max(res, suf[1]);
		else if(i == n-1) res = max(res, pre[n-2]);
		else res = max(res, __gcd(pre[i-1], suf[i+1]));
	}
	cout << res << "\n";
	return 0;
}

