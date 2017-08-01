// 101. Symmetric Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool visit(struct TreeNode* leftNode, struct TreeNode* rightNode){
    if(leftNode == NULL && rightNode == NULL){
        return true;
    }
    
    if(leftNode == NULL){
        return false;
    }
    
    if(rightNode == NULL){
        return false;
    }
    
    if(leftNode->val != rightNode->val){
        return false;
    }
    
    bool result = visit(leftNode->left, rightNode->right);
    if(result == 0){
        return false;
    }
    
    result = visit(leftNode->right, rightNode->left);
    if(result == 0){
        return false;
    }
    
    return true;
}

bool isSymmetric(struct TreeNode* root) {
    return visit(root, root);
}