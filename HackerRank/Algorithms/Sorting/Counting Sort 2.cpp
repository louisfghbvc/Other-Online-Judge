vector<int> countingSort(vector<int> arr) {
    vector<int> fre(100);
    for(int x: arr) fre[x]++;
    
    for(int i = 1; i < 100; ++i)
        fre[i] += fre[i-1];
    
    vector<int> tmp = arr;
    for(int i = tmp.size()-1; i >= 0; --i){
        tmp[--fre[arr[i]]] = arr[i];
    }
    
    return tmp;
}
