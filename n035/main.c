// 35. Search Insert Position

int searchInsert(int* nums, int numsSize, int target) {
    // 使用二元搜尋法
    // 宣告左右邊界的 left 和 right，用來限定範圍。
    int left = 0;
    int right = numsSize - 1;
    int index = 0;
    
    while(1){
        // 如果 left 邊界比 right 邊界大，表示二元搜尋已經結束。
        if(left > right){
            // 將結果和目標數值比較。
            // 結果 < 目標數值，index 就是 insert 的位置。
            // 結果 > 目標數值，index + 1 就是 insert 的位置。
            int resultIndex = (target > nums[index]) ? index + 1 : index;
            
            // 會遇到 left = 0 並且，right = -1 的情況，此時將 index 直接設定成 0。
            return (resultIndex > 0) ? resultIndex : 0;
        }
        
        // 利用 left 和 right，找出中間要比較的 index。
        index = (right + left + 1) / 2;
        
        // 結果 > 目標數值，更新 left 邊界。
        if(target > nums[index]){
            left = index + 1;
        // 結果 < 目標數值，更新 right 邊界。
        }else if(target < nums[index]){
            right = index - 1;
        // 結果 == 目標數值，直接回傳 index。
        }else{
            return index;
        }
    }
}