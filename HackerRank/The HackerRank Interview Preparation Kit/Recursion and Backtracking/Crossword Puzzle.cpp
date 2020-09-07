// Well... Just Backtrack...
// Simulate.

vector<string> arr;
bool flag;
void dfs(int id, vector<string> &crossword){
    if(!flag) return;
    if(id == (int)arr.size()){
        if(flag){
            flag = 0;
        }
        return;
    }
    string word = arr[id];
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            int p = i, q = j, k;
            for(k = 0; k < (int)word.size() && p+k < 10; ++k){
                if(crossword[p+k][q] != '-' && crossword[p+k][q] != word[k]) break;
            }

            if(k == (int)word.size()){
                vector<string> tmp = crossword;
                for(k = 0; k < word.size(); ++k)
                    crossword[p+k][q] = word[k];
                dfs(id+1, crossword);
                if(flag) crossword = tmp;
            }

            for(k = 0; k < (int)word.size() && q+k < 10; ++k){
                if(crossword[p][q+k] != '-' && crossword[p][q+k] != word[k]) break;
            }

            if(k == (int)word.size()){
                vector<string> tmp = crossword;
                for(k = 0; k < (int)word.size(); ++k)
                    crossword[p][q+k] = word[k];
                dfs(id+1, crossword);
                if(flag) crossword = tmp;
            }

        }
    }

}

// Complete the crosswordPuzzle function below.
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    flag = 1;
    string s = "";
    words += ';';
    for(char c: words){
        if(c == ';'){
            arr.push_back(s);
            s = "";
        }
        else s += c;
    }
    dfs(0, crossword);
    return crossword;
}
