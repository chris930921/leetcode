// 27. Remove Element

int removeElement(int* nums, int numsSize, int val) {
    int addIndex = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] != val){
            nums[addIndex] = nums[i];
            addIndex++;
        }
    }
    return addIndex;
}