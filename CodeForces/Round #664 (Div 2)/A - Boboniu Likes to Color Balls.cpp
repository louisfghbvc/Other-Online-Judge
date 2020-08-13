// Problem A.
// math base. 
// and r, g, b can merge into w.
// a correct palindrome must odd cnt <= 1.
// and if odd cnt == 3 or 4
// can filp to 1 or 0. why
// because if odd, odd, odd, even. =>r,g,b,w
// so just change 1 time, become e, e, e, o. so is palindrome.
// just check if num > 0.
// O(1). WA 1 time. because the arr[2] type arr[1]. type mistake. so shit.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long LL;
 
int main()
{
    int t;
    cin >> t;
    vi arr(4);
    while(t--){
        for(int i = 0; i < 4; ++i) cin >> arr[i];
        int c = 0;
        for(int i = 0; i < 4; ++i) if(arr[i] % 2) c++;
        if(c <= 1){
            puts("Yes");
        }
        else{
            if(!arr[0] || !arr[1] || !arr[2]) puts("No");
            else if(c >= 3) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
