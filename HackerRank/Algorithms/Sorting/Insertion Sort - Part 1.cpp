void insertionSort1(int n, vector<int> arr) {
    int target = arr[n-1];
    bool find = false;
    for(int i = n-2; i >= 0; --i){
        if(arr[i] > target){
            for(int j = 0; j <= i; ++j)
                cout << arr[j] << " ";
            for(int j = i; j < n-1; ++j)
                cout << arr[j] << " ";
            cout << "\n";
        }
        else{
            for(int j = 0; j <= i; ++j)
                cout << arr[j] << " ";
            cout << target << " ";
            for(int j = i+1; j < n-1; ++j)
                cout << arr[j] << " ";
            cout << "\n";
            find = true;
            break;
        }
    }
    if(!find){
        cout << target << " ";
        for(int j = 0; j < n-1; j++)
            cout << arr[j] << " \n"[j==n-2];
    }
}
