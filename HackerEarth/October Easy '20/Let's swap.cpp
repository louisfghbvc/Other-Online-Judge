// Well, a observe. hard to think.
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

// Abs magic
// so Swap(p[i], p[j])
// ans -= |p[i] - i| + |p[j] - j|
// ans += |p[i] - j| + |p[j] - i|

// so we know thar |x|+|y| => |x+-y|. say |x+y| or |x-y|.
// so |p[i]-j + p[j]-i| or |p[i]-j - (p[j]-i)|
// |p[i]-i + p[j]-j| or |p[i]+i - (p[j]+j)|
// so total max is max(p[i]-i)+max2(p[i]-i) or max(p[i]+i)-min(p[i]+i).

// same concept.
// O(N). prefer this
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
	LL mx[2]; // 0: p[i]+i, 1: p[i]-i 
	LL mn[2];
	mx[0] = mx[1] = mn[1] = INT_MIN;
	mn[0] = INT_MAX;
	for(LL i = 1; i <= n; ++i){
		res += abs(arr[i]-i);
		mx[0] = max(mx[0], arr[i]+i - abs(arr[i]-i));
		mn[0] = min(mn[0], arr[i]+i + abs(arr[i]-i));

		if(mx[1] < arr[i]-i - abs(arr[i]-i)){
			if(mn[1] < mx[1]) mn[1] = mx[1];
			mx[1] = arr[i]-i - abs(arr[i]-i);
		}
		else if(mn[1] < arr[i]-i - abs(arr[i]-i)) mn[1] = arr[i]-i - abs(arr[i]-i);
	}

	LL fin = max(mx[1]+mn[1], mx[0]-mn[0]);
	cout << res + fin << "\n";

	return 0;
}
