/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    return travel(root, 0);
}

int travel(struct TreeNode* node, int level){
    if(node == NULL) return level;
    
    int leftLevel = travel(node->left, level + 1);
    int rightLevel = travel(node->right, level + 1);
    
    return (leftLevel > rightLevel) ? leftLevel : rightLevel;
}