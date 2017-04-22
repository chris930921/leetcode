
// 543. Diameter of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
 // 找出樹的高度。
 int deepOfBinaryTree(struct TreeNode* root){
     // 到底部時結束遞迴。
     if(root == NULL){
         return 0;
     }
     
     // 找出左子樹的高度。
     int leftMax = deepOfBinaryTree(root->left);
     // 找出右子樹的高度。
     int rightMax = deepOfBinaryTree(root->right);
     // 比較左、右子樹，最大的高度才是整顆樹的高度。
     return (leftMax > rightMax) ? leftMax + 1 : rightMax + 1;
 }
 
int diameterOfBinaryTree(struct TreeNode* root) {
    // 到底部時結束遞迴。
    if(root == NULL){
        return 0;
    }
    
    // 找出左子樹的高度。
    int leftDeep = deepOfBinaryTree(root->left);
    // 找出右子樹的高度。
    int rightDeep = deepOfBinaryTree(root->right);
    // 兩邊高度加起來，就是目前任兩點的最長距離。
    int linkMaxLength = leftDeep + rightDeep;
    
    // 找出左邊的最長距離。
    int leftMax = diameterOfBinaryTree(root->left);
    // 找出右邊的最長距離。
    int rightMax = diameterOfBinaryTree(root->right);
    
    // 比較以上三者，何者的距離最長。
    if(leftMax > linkMaxLength){
        linkMaxLength = leftMax;
    }
    if(rightMax > linkMaxLength){
        linkMaxLength = rightMax;
    }
    
    // 回傳最長距離。
    return linkMaxLength;
}