int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    // 假設原始輸入是 [4,3,2,7,8,2,3,1]。
    for(int i = 0; i < numsSize; i++){
        // 由於有出現的數字會被轉為負數，所以需取絕對值。
        int index = abs(nums[i]) - 1;
        if(nums[index] > 0){
            // 利用 signed 紀錄哪些數字有出現在輸入中。
            // 這麼做的優點是不需額外空間，且原始資料不會被改變。
            nums[index] = -nums[index];
        }
    }
    
    // 標記後輸入改變為 [-4,-3,-2,-7, 8, 2,-3,-1]
    // 找出大於 0 的數量。
    *returnSize = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0){
            (*returnSize)++;
        }
    }
    
    // 建立陣列儲存結果。
    int* results = (int*)calloc(*returnSize, sizeof(int));
    int pushIndex = 0;
    // 找出大於 0 的數值的 position 放入 results。
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > 0){
            results[pushIndex] = i + 1;
            pushIndex++;
        }
    }
    
    // [8,2] 的 position 分別是 [5,6]，代表 5、6 不在原始的輸入中。
    // 回傳 [5,6]。
    return results;
}