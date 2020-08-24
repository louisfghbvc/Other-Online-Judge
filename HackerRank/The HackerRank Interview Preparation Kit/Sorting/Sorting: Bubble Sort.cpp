// Just bubble sort

void countSwaps(vector<int> a) {
    int n = a.size();
    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j+1 < n; ++j){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                res++;
            }
        }
    }
    cout << "Array is sorted in " << res << " swaps.\n";
    cout << "First Element: " << a[0] << "\n";
    cout << "Last Element: " << a.back() << "\n";  
}
