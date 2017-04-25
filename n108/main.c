// 108. Convert Sorted Array to Binary Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void convertSortArrayToBlanceTree(struct TreeNode** node, int start, int* nums, int numsSize){
    // 陣列長度為 0 時停止遞迴。
    if(numsSize <= 0){
        return;
    }
    
    // 如果是偶數長度陣列 [0, 1, 2, 3]，中間點為 1，所以左長 1，右長 2。
    // 如果是奇數長度陣列 [0, 1, 2, 3, 4]，中間點為 2，所以左長 2，右長 2。
    
    // 找出左半邊陣列的長度
    int leftSize = (numsSize - 1) / 2;
    // 找出右半邊陣列的長度。
    int rightSize = numsSize / 2;
    
    // 找出目前節點屬於陣列的哪個 index。
    int mid = start + leftSize;
    
    // 找出左半邊陣列的起始位置。
    int leftStart = start;
    // 找出左半邊陣列的起始位置。
    int rightStart = mid + 1;
    
    // 將正中間的元素設定為節點。
    *node = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    (*node)->val = nums[mid];
    
    // 繼續平分左半邊的陣列，並將正中間的元素設定為節點。
    convertSortArrayToBlanceTree(&((*node)->left), leftStart, nums, leftSize);
    // 繼續平分右半邊的陣列，並將正中間的元素設定為節點。
    convertSortArrayToBlanceTree(&((*node)->right), rightStart, nums, rightSize);
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    
    struct TreeNode* root = NULL;
    
    // 假設輸入是 [0,1, 2, 3, 4, 5]。
    // 應該產生的二元樹結果為如下，n 是 null 空節點的意思。
    //       2
    //     0   4
    //    n 1 3 5
    
    convertSortArrayToBlanceTree(&root, 0, nums, numsSize);
    
    return root;
}