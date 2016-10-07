/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int max = 0;
    for(int i = 0; i < nums1Size; i++){
        max = (nums1[i] > max) ? nums1[i] : max;
    }
    for(int i = 0; i < nums2Size; i++){
        max = (nums2[i] > max) ? nums2[i] : max;
    }
    
    max += 1;
    int* numberMap = (int*)calloc(max, sizeof(int));
    for(int i = 0; i < nums1Size; i++){
        numberMap[nums1[i]] = 1;
    }
    
    *returnSize = 0;
    for(int i = 0; i < nums2Size; i++){
        if(numberMap[nums2[i]] == 1){
            numberMap[nums2[i]] = 2;
            (*returnSize)++;
        }
    }
    
    int* result = (int*)calloc(*returnSize, sizeof(int));
    int lastIndex = 0;
    for(int i = 0; i < max; i++){
        if(numberMap[i] == 2){
            result[lastIndex] = i;
            lastIndex++;
        }
    }
    
    return result;
}