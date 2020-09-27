// so observe that just add something that bit is enough.
// do all 32 bit prefix.

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5+5;
LL arr[N];
LL pre[N][35];

int main(){
	int n, q;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	memset(pre, 0, sizeof pre);
	// each bit prefix. count zero
	for(int b = 0; b < 30; ++b)
		for(int i = 0; i < n; ++i){
			LL mask = 1LL<<b, all1 = mask-1;
			pre[i+1][b] = pre[i][b] + ( (arr[i]&mask) ? 0 : mask-(arr[i]&all1) );
		}
			

	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		LL res = pre[r][29]-pre[l-1][29];
		for(int i = 28; i >= 0; --i){
			res = min(res, pre[r][i]-pre[l-1][i]);
		}
		cout << res << "\n";
	}
}

