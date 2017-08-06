// 594. Longest Harmonious Subsequence

// 用於快速排序的比對。
int compare(const void *value1, const void *value2){
    return *(int *)value1 - *(int *)value2;
}

int findLHS(int* nums, int numsSize) {
    // 使用 stdlib.h 的快速排序，泡沫排序法太慢。
    qsort((void *)nums, numsSize, sizeof(int), compare); 
    
    int max = 0;
   
    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i+1]-nums[i] == 1){
            int count = 0;
            for(int j = 0; j < numsSize; j++){
                count += (nums[j] == nums[i] || nums[j] == nums[i+1]);
            }
            
            if(count > max){
                max = count;
            }
        }
    }
    
    return max;
} 