// Just... O(N).

vector<int> breakingRecords(vector<int> scores) {
    int low = scores[0], high = scores[0], low_cnt = 0, high_cnt = 0;
    for(int x: scores){
        if(x > high) high_cnt++, high = x;
        if(x < low) low_cnt++, low = x;
    }
    return {high_cnt, low_cnt};
}
