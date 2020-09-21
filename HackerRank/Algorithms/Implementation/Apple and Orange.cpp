// Boring.

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    for(int &x: apples) x = a+x;
    for(int &x: oranges) x = b+x;

    int ac = 0, oc = 0;
    for(int x: apples) if(x >= s && x <= t) ac++; 
    for(int x: oranges) if(x >= s && x <= t) oc++; 

    cout << ac << endl;
    cout << oc << endl;
}
