// fib tweak, linear algebra.
// O(M^3logn)
// time limit... mod cost a lot. after add then mod once.
// ans = A^n-1 * base.
// idea is find A.
// and precompute 1e9. 

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL mod = 1e9+7;
LL a, b, c, d, e, f;
LL F[2], G[2], H[2];

LL M[31][5][5];

void multiply(LL A[5][5], LL B[5][5], LL C[5][5]){
	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 5; ++j){
			C[i][j] = 0;
			for(int k = 0; k < 5; ++k)
				C[i][j] += A[i][k] * B[k][j];
			C[i][j] %= mod;
		}			
}

inline void pre(){
	H[0] = (e*F[0] + f*G[0]) % mod;
	H[1] = (e*F[1] + f*G[1] + H[0]) % mod;
	M[0][0][0] = a, M[0][0][3] = b;
	M[0][1][0] = 1;
	M[0][2][1] = d, M[0][2][2] = c;
	M[0][3][2] = 1;
	M[0][4][0] = e*a%mod, M[0][4][1] = f*d%mod,	M[0][4][2] = f*c%mod, M[0][4][3] = e*b%mod, M[0][4][4] = 1;
	for(int i = 1; i < 30; ++i)
		multiply(M[i-1], M[i-1], M[i]);
}

int main() {
	scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
	scanf("%lld %lld", &F[0], &F[1]);
	scanf("%lld %lld", &G[0], &G[1]);
	pre();
	int q;
	scanf("%d", &q);
	while(q--){
		LL ans[5] = {F[1], F[0], G[1], G[0], H[1]};
		int n;
		scanf("%d", &n);
		if(n <= 1){
			printf("%lld\n", H[n]);
			continue;
		}
		n--;
		for(int i = 0; i < 30; ++i){
			if(n & (1<<i)){
				LL tmp[5] = {0, 0, 0, 0, 0};
				for (int j = 0; j < 5; ++j){
					for (int k = 0; k < 5; ++k)
						tmp[j] += M[i][j][k] * ans[k];
					tmp[j] %= mod;
				}
				for (int j = 0; j < 5; ++j)
					ans[j] = tmp[j];
			}
		}
		printf("%lld\n", ans[4]);
	}
	return 0;
}
