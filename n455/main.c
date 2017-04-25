// 氣泡排序。
void bubbleSort(int* nums, int numsSize){
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize - 1; j++){
            if(nums[j] > nums[j+1]){
                int tmp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}

// 用於快速排序的比對。
int compare(const void *value1, const void *value2){
    return *(int *)value1 - *(int *)value2;
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    // 用氣泡排序 submit 時間過不了，太慢了。
    // bubbleSort(g, gSize); 
    // bubbleSort(s, sSize);
    
    // 使用 stdlib.h 的快速排序
    qsort((void *)g, gSize, sizeof(int), compare); 
    qsort((void *)s, sSize, sizeof(int), compare);
    
    // 先指定一個 child。
    int childIndex = 0;
    int cookieIndex = 0;
    
    // 找完所有 child 或找完所有 cookie 後就停止。
    while(childIndex < gSize && cookieIndex < sSize){
        // 將 cookieIndex 遞增，直到發現可以 content 的 cookie。
    	if(g[childIndex] <= s[cookieIndex]){
    		// 指定下一個 child，繼續尋找。
    		childIndex++;
    	}
    	cookieIndex++;
    }
    
    // 指定到第幾個 child，就代表有多少個 child match，直接回傳即可。
    return childIndex;
}