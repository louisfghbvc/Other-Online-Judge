bool solve(vector<int>& nums) {
    // goal: each move take the sublist [1, 1] to 0
    // take 2
    // idea: convert list to some nubmers
    // 1 1 1 1 -> 2 possible, first make 2, or make 1 
    // after we convert sublist to number
    // (a, b, c) ...

    // consider a single pile a
    //n 0 1 2 3 4 5 6
    //g 0 0 1 1 2 0 3
    // g(4) = mex{g[2]^g[0], g[1]^g[1]} = 2
    // g(5) = mex{g[3]^g[0], g[1]^g[2]} = 0
    // g(6) = mex{g[4]^g[0], g[1]^g[3], g[2]^g[2]} = {2, 1, 0} = 3

    // build g value
    vector<int> g(55);
    for (int i = 2; i <= 55; ++i) {
        set<int> st;
        for(int l = i-2, r = 0; l >= r; --l, ++r)
            st.insert(g[l]^g[r]);
        int mex = 0;
        while (st.count(mex)) mex++;
        g[i] = mex;
    }

    // just the multi-nim-game xor all of them

    vector<int> game;
    for (int i = 0, j; i < nums.size(); i = j) {
        j = i;
        while (j < nums.size() && nums[i] == nums[j]) j++;
        if (nums[i])
            game.push_back(j-i);
    }

    int value = 0;
    for (int x: game)
        value ^= g[x];
    return value;
}
