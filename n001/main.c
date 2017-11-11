// 1. Two Sum

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* results = (int*) calloc(2, sizeof(int));
    
    // 走訪每一個數值。
    for(int i = 0; i < numsSize; i++){
        results[0] = i;
        // 計算目前數值和目標數值的差值。
        int expectValue = target - nums[i];
        
        for(int j = i + 1; j < numsSize; j++){
            // 相等就直接回傳，題目說只有唯一解。
            if(nums[j] == expectValue){
                results[1] = j;
                return results;
            }
        }
    }
    
    return results;
}