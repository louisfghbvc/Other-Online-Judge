// So just convert to array. and compare array. O(N)

vector<int> toA(string &s){
    s += '.';
    int t = 0;
    vector<int> res;
    for(char c: s){
        if(c == '.'){
            res.push_back(t);
            t = 0;
        }
        else t = t*10 + c-'0';
    }
    s.pop_back();
    return res;
}

bool solve(string older, string newer) {
    auto A = toA(older), B = toA(newer);
    return A < B;
}
