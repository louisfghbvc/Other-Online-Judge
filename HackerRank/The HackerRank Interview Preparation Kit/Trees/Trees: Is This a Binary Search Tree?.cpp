// O(N). So maintain a range in current level.
// check range is valid. and down array.
// simple right? 

bool checkBST(Node* root, int mn, int mx){
    if(!root) return true;
    if(root->data <= mn || root->data >= mx) return false;
    return checkBST(root->left, mn, root->data) && checkBST(root->right, root->data, mx);
}
bool checkBST(Node* root) {
      return checkBST(root, -5, 100000);
}

// O(N). inorder and check array. extra space.

vector<int> arr;
void dfs(Node* root){
    if(!root) return;
    dfs(root->left);
    arr.push_back(root->data);
    dfs(root->right);
}
bool checkBST(Node* root) {
    arr.clear();
    dfs(root);
    for(int i = 1; i < arr.size(); ++i){
        if(arr[i] <= arr[i-1]) return false;
    }
    return true;
}
