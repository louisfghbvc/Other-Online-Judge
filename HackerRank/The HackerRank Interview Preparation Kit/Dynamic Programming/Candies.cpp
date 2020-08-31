// Actually. just check left or right.
// and determine current.
// O(N). dp shape.

const int N = 1e5+5;
int memo[N];
int A[N];

int dp(int x){
    if(memo[x] != -1) return memo[x];
    int mid = A[x], left = A[x-1], right = A[x+1];
    if(mid > left && mid > right){
        memo[x] = max(dp(x-1), dp(x+1))+1;
    }
    else if(mid > left){
        memo[x] = dp(x-1)+1;
    }
    else if(mid > right){
        memo[x] = dp(x+1)+1;
    }
    else memo[x] = 1;
    return memo[x];
} 

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    long res = 0;
    memset(memo, -1, sizeof memo);
    memset(A, 0, sizeof A);
    A[0] = A[n+1] = (int)1e7;

    for(int i = 0; i < n; ++i){
        A[i+1] = arr[i];
    }

    for(int i = 1; i <= n; ++i){
        res += dp(i);
    }
    
    return res;
}

// Two pass, just like monotonous.
// easy to observe the minimum is build left to right.
// if up add 1, else set to 1
// then right to left again use prev array to adjust.
// O(N)
long candies(int n, vector<int> arr) {
    long res = 0;
    vector<int> candy(n);
    candy[0] = 1;

    for(int i = 1; i < n; ++i){
        if(arr[i] > arr[i-1]) candy[i] = candy[i-1]+1;
        else candy[i] = 1;
    }

    for(int i = n-1; i >= 1; --i){
        if(arr[i] < arr[i-1]) candy[i-1] = max(candy[i]+1, candy[i-1]);
    }

    // for(int x: candy) cout << x << " ";
    // cout << "\n";

    for(int x: candy) res += x;
    return res;
}
