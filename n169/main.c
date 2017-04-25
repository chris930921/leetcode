// 169. Majority Element

// 用於快速排序的比對。
int compare(const void *value1, const void *value2){
    return *(int *)value1 - *(int *)value2;
}

int majorityElement(int* nums, int numsSize) {
    // 設定符合條件的的次數，目標是 numsSize 的一半以上。
    int majority = numsSize / 2;
    
    // 使用 stdlib.h 的快速排序，泡沫排序法太慢。
    qsort((void *)nums, numsSize, sizeof(int), compare); 
    
    int repeatCount = 0;
    int currentNum = nums[0];
    int result = 0;
    // 比對每種數字出現的次數
    for(int i = 0; i < numsSize; i++){
        // 如果出現和上次不同的數字，將 repeatCount 歸零，重新計算。
        if(currentNum != nums[i]){
            currentNum = nums[i];
            repeatCount = 0;
        }
        
        repeatCount++;
        
        // 如果重複出現的次數大於 majority，紀錄位置 (result) 並終止迴圈。
        if(repeatCount > majority){
            result = i;
            break;
        }
    }
    
    // 回傳結果。
    return nums[result];
}