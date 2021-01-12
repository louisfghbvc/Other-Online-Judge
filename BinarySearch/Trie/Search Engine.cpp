// Trie + Backtracking, Heuristic algorithm.

struct Trie{
    Trie* next[26];
    bool isWord;
    Trie(bool isW = false){
        memset(next, 0, sizeof next);
        isWord = isW;
    }
};

class SearchEngine {
public:
    Trie* root = NULL;
    SearchEngine() {
        root = new Trie();
    }

    void add(string word) {
        Trie* tmp = root;
        for(int i = 0; i < word.size(); ++i){
            int c = word[i]-'a';
            if(!tmp->next[c]) tmp->next[c] = new Trie();
            tmp = tmp->next[c];
        }
        tmp->isWord = true;
    }

    bool exists(string word) {
        return search(word, 0, root);
    }

    bool search(string &s, int i, Trie* cur){
        if(!cur) return false;
        if(i == s.size()) return cur->isWord;
        if(s[i] == '.'){
            for(int k = 0; k < 26; ++k){
                if(search(s, i+1, cur->next[k])) return true;
            }
            return false;
        }
        return search(s, i+1, cur->next[s[i]-'a']);
    }
};
