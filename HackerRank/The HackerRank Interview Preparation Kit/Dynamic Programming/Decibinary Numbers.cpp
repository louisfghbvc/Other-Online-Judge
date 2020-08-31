// See the tutorial...
// well... from BF to Recursive.
// and change problem to get gth number.
// Very hard, maybe not my level to solve..

const int D = 25;
const int S = 3e5+5;
long dp[D][S];
long pre[S];

// calculate the number of value s(digits length == d)
long func(int d, long s){
    if(!d && !s) return 1;
    if(!d && s) return 0;
    if(s < 0) return 0;
    if(dp[d][s] != -1) return dp[d][s];
    long res = 0;
    for(int i = 0; i <= 9; ++i){
        res += func(d-1, s-i*(1<<(d-1)) );
    }
    return dp[d][s] = res;
}

void predo(){
    memset(dp, -1, sizeof dp);
    for(int i = 0; i <= 300000; ++i){
        pre[i] = func(20, i);
        //cout << i << " num:" << pre[i] << "\n";
        if(i) pre[i] += pre[i-1];
    }
}

// Complete the decibinaryNumbers function below.
long decibinaryNumbers(long x) {
    if(x == 1) return 0;
    int l = 0, r = 300000;
    int val = 300000;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(pre[mid] >= x){
            val = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    // turn to find gth decbinary.
    long g = x-pre[val-1];
    int d; // digit at least get gth number
    for(d = 0; func(d, val) < g; ++d);

    cerr << "get new gth: " << g << "\n";
    cerr << "get val: " << val << "\n";
    cerr << "how manys digits " << d << "\n";

    long ans = 0;
    while(d > 0){
        long tmp = 0;
        for(int i = 0; i <= 9; ++i){
            if(val - i*(1<<(d-1)) >= 0) tmp += func(d-1, val - i*(1<<(d-1)));
            if(tmp >= g){
                g -= tmp-func(d-1, val - i*(1<<(d-1)));
                cerr << i;
                ans = ans*10 + i;
                val -= i*(1<<(d-1));
                break;
            }
        }
        d--;
    }
    cerr << "\n";
    
    return ans;
}
