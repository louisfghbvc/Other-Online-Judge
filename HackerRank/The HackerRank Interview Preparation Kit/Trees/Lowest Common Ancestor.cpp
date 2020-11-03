// O(logN).
// just recursive. trust function help. 3 case.
// both big, both small, or else return root

Node *lca(Node *root, int v1,int v2) {
    if(!root) return NULL;
    if(v1 > root->data && v2 > root->data) return lca(root->right, v1, v2);
    else if(v1 < root->data && v2 < root->data) return lca(root->left, v1, v2);
    return root;
}
