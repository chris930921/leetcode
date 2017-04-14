// 349. Intersection of Two Arrays

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    // 例如輸入 [1, 2, 3, 2, 1, 4]、[1, 2, 2, 3, 3]。
    // 找出最大數值 4。
    int max = 0;
    for(int i = 0; i < nums1Size; i++){
        max = (nums1[i] > max) ? nums1[i] : max;
    }
    for(int i = 0; i < nums2Size; i++){
        max = (nums2[i] > max) ? nums2[i] : max;
    }
    
    // 建立長度為 5 的陣列，第 0 個 index 不會用到，numberMap 內容為 [0, 0, 0, 0, 0]。
    // 找出 nums1 有的數字 (1, 2, 3, 4) 改變為 1，numberMap 內容為 [0, 1, 1, 1, 1]。
    max += 1;
    int* numberMap = (int*)calloc(max, sizeof(int));
    for(int i = 0; i < nums1Size; i++){
        numberMap[nums1[i]] = 1;
    }
    
    // 找出 nums2 有的數字 (1, 2, 3) 改變為 2，numberMap 內容為 [0, 2, 2, 2, 1]。
    *returnSize = 0;
    for(int i = 0; i < nums2Size; i++){
        if(numberMap[nums2[i]] == 1){
            numberMap[nums2[i]] = 2;
            (*returnSize)++;
        }
    }
    
    // 找出 numberMap 有 2 的 index，該 index 就代表有同時出現在 nums1 和 nums2 的數字。
    // numberMap 目前內容為 [0, 2, 2, 2, 1]，有 2 的 index 是 (1, 2, 3)。
    int* result = (int*)calloc(*returnSize, sizeof(int));
    int lastIndex = 0;
    for(int i = 0; i < max; i++){
        if(numberMap[i] == 2){
            result[lastIndex] = i;
            lastIndex++;
        }
    }
    
    // 回傳結果 [1, 2, 3]。
    return result;
}