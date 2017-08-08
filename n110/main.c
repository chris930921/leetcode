// 110. Balanced Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int visit(struct TreeNode* node, int depth, bool* result){
    if(node == NULL){
        return depth;
    }
    
    int leftDepth = visit(node->left, depth + 1, result);
    int rightDepth = visit(node->right, depth + 1, result);
    
    if(leftDepth > rightDepth){
        *result &= (leftDepth - rightDepth) <= 1;
        return leftDepth;
    }else{
        *result &= (rightDepth - leftDepth) <= 1;
        return rightDepth;
    }
}

bool isBalanced(struct TreeNode* root) {
    bool result = true;
    visit(root, 0, &result);
    
    return result;
}