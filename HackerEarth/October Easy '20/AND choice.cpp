// build a int Trie.
// so search now, and after search add to trie.
// O(NlogN). sort.

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
	node* next[2];
	node(){
		memset(next, 0, sizeof next);
	}
};
 
node* root;
 
void add(LL x){
	node* cur = root;
	for(int i = 31; i >= 0; --i){
		bool bit = (1LL<<i)&x;
		if(!cur->next[bit]) cur->next[bit] = new node();
		cur = cur->next[bit];
	}
}
 
LL search(LL x){
	node* cur = root;
	LL res = 0;
	for(int i = 31; i >= 0 && cur; --i){
		bool bit = (1LL<<i)&x;
		if(cur->next[bit]){
			if(bit) res |= (1LL<<i);
			cur = cur->next[bit];
		}
		else{
			cur = cur->next[!bit];
		}
	}
	return res;
}
 
const int N = 3e5+5;
LL arr[N];
 
int main() {
	// cout << (1LL<<30) << "\n";
	root = new node();
	int n;
	cin >> n;
 
	for(int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr+n);
	
	LL mx = 0;
	for(int i = 0; i < n; ++i){
		mx = max(search(arr[i]), mx);
		add(arr[i]);
	}
 
	cout << mx << "\n";
	return 0;
}
