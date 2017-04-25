/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    invert(root);
    return root;
}

void invert(struct TreeNode* node){
    if(node == NULL){
        return;
    }
    
    invert(node->left);
    invert(node->right);
    
    struct TreeNode* tmp = node->left;
    node->left = node->right;
    node->right = tmp;
}