vector<int> countingSort(vector<int> arr) {
    vector<int> fre(100);
    for(int x: arr)
        fre[x]++;
    return fre;
}
