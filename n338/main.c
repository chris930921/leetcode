/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    *returnSize = num + 1;
    int* array = (int*)calloc(*returnSize, sizeof(int));
    
    for(int i = 0; i <= num; i++){
        int count = 0;
        int last = i;
        int current = i;
        while(current != 0){
            if(current & 0x1){
                count++;
                last = current;
            }
            current >>= 1;
        };
        array[i] = count;
    }
    
    return array;
}