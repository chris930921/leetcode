// 350. Intersection of Two Arrays II

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* nums1Flags = (int*)calloc(nums1Size, sizeof(int));
    int* nums2Flags = (int*)calloc(nums2Size, sizeof(int));
    
    int* results = (int*)calloc(nums1Size+nums2Size, sizeof(int));
    *returnSize = 0;
    
    // 例如輸入 [-2147483648, 1, 2, 3]、[2, -2147483648, 1, -2147483648]。
    // nums1 陣列 [-2147483648, 1, 2, 3] 的 flag 陣列內容為 [0, 0, 0, 0]。
    // nums2 陣列 [3, -2147483648, 1, -2147483648] 的 flag 陣列內容為 [0, 0, 0, 0]。
    
    // 從 nums1 取出 -2147483648。
    // 比對 nums2 的 3，不匹配所以跳過。
    // 比對 nums2 的 -2147483648，匹配所以修改 nums2 的 flag 陣列為 [0, 1, 0, 0]。
    // 放進 results 中，內容為 [-2147483648, 0, 0, 0, 0, 0, 0, 0]。
    
    // 從 nums1 取出 1。
    // 比對 nums2 的 3，不匹配所以跳過。
    // 比對 nums2 的 -2147483648，其 flag 已經是 1 所以跳過。
    // 比對 nums2 的 1，匹配所以修改 nums2 的 flag 陣列為 [0, 1, 1, 0]。
    // 放進 results 中，內容為 [-2147483648, 1, 0, 0, 0, 0, 0]。
    
    // 從 nums1 取出 2。
    // 比對 nums2 的 3，不匹配所以跳過。
    // 比對 nums2 的 -2147483648，其 flag 已經是 1 所以跳過。
    // 比對 nums2 的 1，其 flag 已經是 1 所以跳過。
    // 比對 nums2 的 -2147483648，其 flag 已經是 1 所以跳過。
    // 沒有匹配的結果，不放入 results 中。
    for(int i = 0; i < nums1Size; i++){
        for(int j = 0; j < nums2Size; j++){
            if(nums2Flags[j] == 1){
                continue;
            }
            
            if(nums1[i] == nums2[j]){
                results[(*returnSize)] = nums1[i];
                (*returnSize)++;
                
                nums2Flags[j] = 1;
                break;
            }
        }
    }
    
    return results;
}