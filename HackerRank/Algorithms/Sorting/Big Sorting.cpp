vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), [](string &a, string &b){
        return a.size() != b.size() ? a.size() < b.size() : a < b;  
    });
    return unsorted;
}
