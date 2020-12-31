// Big Int. Factorials use array.
// O(N).

void extraLongFactorials(int n) {
    int big[300] = {1}; 
    int digit = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < digit; ++j) big[j] *= i;
        for(int j = 0; j < digit; ++j){
            big[j+1] += big[j] / 10;
            if(j + 1 >= digit && big[j + 1] > 0) ++digit;
            big[j] %= 10;
        }
    }
    for(int i = digit-1; i >= 0; --i)
        cout << big[i];
    cout << "\n";
}
