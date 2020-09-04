// O(N). Simple Recursive.

int height(Node* root) {
    // Write your code here.
    if(!root) return -1;
    return 1+max(height(root->left), height(root->right));
}
