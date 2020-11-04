#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n][3];
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 3; ++j)
			cin >> arr[i][j];
	}

	vector<int> dp(3);
	for(int j = 0; j < 3; ++j) dp[j] = arr[0][j];

	for(int i = 1; i < n; ++i){
		vector<int> dp1(3);
		dp1[0] = arr[i][0] + min(dp[1], dp[2]);
		dp1[1] = arr[i][1] + min(dp[0], dp[2]);
		dp1[2] = arr[i][2] + min(dp[0], dp[1]);	
		dp = dp1;
	}

	cout << *min_element(dp.begin(), dp.end()) << "\n";

}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
}
