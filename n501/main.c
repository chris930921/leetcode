// 501. Find Mode in Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void visit(struct TreeNode* node, int* previousValue, int* maxValue, int* count, int** results, int* returnSize){
    if(node == NULL){
        return;
    }
    
    visit(node->left, previousValue, maxValue, count, results, returnSize);
    
    if(*previousValue != node->val){
        *previousValue = node->val;
        *count = 0;
    }
    
    (*count)++;
    
    if(*count > *maxValue){
        *returnSize = 0;
        *maxValue = *count;
    }
    
    if(*count == *maxValue){
        int newSize = *returnSize + 1;
        int* newResults = (int*)calloc(newSize, sizeof(int));

        for(int i = 0; i < *returnSize; i++){ 
            newResults[i] = (*results)[i];
        }

        newResults[newSize - 1] = *previousValue;
        *results = newResults;
        *returnSize = newSize;
    }
    
    visit(node->right, previousValue, maxValue, count, results, returnSize);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    int* results;
    int previousValue = -1;
    int maxValue = 0;
    int count = 0;
    visit(root, &previousValue, &maxValue, &count, &results, returnSize);
    return results;
}