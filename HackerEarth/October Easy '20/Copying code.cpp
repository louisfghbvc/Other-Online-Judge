// Simple.

#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, i;
	cin >> n >> i;
 
	int first = 2+n-i+2;
	int second = 2*(n-i);
	cout << min(first, second) << "\n";
	return 0;
}
