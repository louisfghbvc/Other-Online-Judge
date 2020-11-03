// O(N). Just a tree traversal.

void decode_huff(node * root, string s) {
    string res = "";
    node *cur = root;
    for(char c: s){
        if(c == '1') cur = cur->right;
        else cur = cur->left;
        if(cur && cur->data){
            res += cur->data;
            cur = root;
        }
    }
    cout << res << "\n";
}
