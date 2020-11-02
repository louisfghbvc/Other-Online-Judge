// think 3, 1 3 2
// 4: 1 4 2 3, but 3 go begin 3 1 4 2.
// 5: 1 5 2 4 3 => 3 1 5 2 4.
// base: n*(n-1)/2
// but -1 and add n/2 cuz go to begin.

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	int t;
	cin >> t;
	while(t--){
		LL n;
		cin >> n;
		if(n==1){
			cout << 1 << endl;
			continue;
		}
		cout << (n * (n - 1) / 2) - 1 + n / 2 << "\n";
	}
	return 0;
}

