// O(sqrt(n))

string primality(int n) {
    bool ok = 1;
    if(n == 1) ok = 0;
    for(int i = 2; i <= sqrt(n) && ok; ++i){
        if(n%i == 0) ok = 0;
    }
    return ok ? "Prime" : "Not prime";
}

// Can preprocess the prime table. make faster.
