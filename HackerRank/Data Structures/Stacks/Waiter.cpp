// Boring. just build prime table. and simulate.
// O(NlogN)

const int N = 1e4+5;
bool np[N];
vector<int> p;

void init(){
    for(int i = 2; i < N; ++i){
        if(!np[i]){
            p.push_back(i);
            for(int j = 2*i; j < N; j+=i)
                np[j] = 1;
        }
    }
}

vector<int> waiter(vector<int> number, int q) {
    init();
    vector<int> b[q];
    for(int k = 0; k < q; ++k){
        int prime = p[k];
        vector<int> A;
        for(int i = (int)number.size()-1; i >= 0; --i){
            int v = number.back(); number.pop_back();
            if(v % prime == 0) b[k].push_back(v);
            else A.push_back(v);
        }
        number = A;
    }

    vector<int> res;
    for(int i = 0; i < q; ++i){
        for(int k = (int)b[i].size()-1; k >= 0; --k){
            res.push_back(b[i][k]);
        }
    }
    for(int i = (int)number.size()-1; i >= 0; --i){
        res.push_back(number[i]);
    }
    return res;
}
