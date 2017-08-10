// 235. Lowest Common Ancestor of a Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL){
        return root;
    }
    
    if(root == p){
        return root;
    }
    
    if(root == q){
        return root;
    }
    
    struct TreeNode* leftFindResult = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* rightFindResult = lowestCommonAncestor(root->right, p, q);
    
    if(leftFindResult == NULL){
        return rightFindResult;
    }
    
    if(rightFindResult == NULL){
        return leftFindResult;
    }
    
    return root;
}