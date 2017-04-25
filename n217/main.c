// 217. Contains Duplicate

// 用於快速排序的比對。
int compare(const void *value1, const void *value2){
    return *(int *)value1 - *(int *)value2;
}

bool containsDuplicate(int* nums, int numsSize) {
    
    // 使用 stdlib.h 的快速排序
    qsort((void *)nums, numsSize, sizeof(int), compare); 
    
    // 紀錄上一個數值，和現在數值比對是否重複。
    int previous = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(previous == nums[i]){
            return true;
        }
        previous = nums[i];
    }
    
    return false;
}