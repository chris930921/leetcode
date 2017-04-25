char* goldMedal = "Gold Medal";
char* silverMedal = "Silver Medal";
char* bronzeMedal = "Bronze Medal";
 
char** findRelativeRanks(int* nums, int numsSize, int* returnSize) {
    // 複製輸入的陣列，並記錄每個數值的位置。
    int* sortNums = (int*)calloc(numsSize, sizeof(int));
    int* positions = (int*)calloc(numsSize, sizeof(int));
    for(int i = 0; i < numsSize; i++){
        sortNums[i] = nums[i];
        positions[i] = i; 
    }
    
    // 泡沫排序，排序數值並同時排序位置。
    int tmp = 0;
    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize - i - 1; j++){
            if(sortNums[j] < sortNums[j+1]){
                tmp = sortNums[j+1];
                sortNums[j+1] = sortNums[j];
                sortNums[j] = tmp;
                
                tmp = positions[j+1];
                positions[j+1] = positions[j];
                positions[j] = tmp;
            }
        }
    }
    
    // 先建立好所有的名次的字串，這裡設定最少要有三個字串可以放入
    // "Gold Medal"、"Silver Medal"、"Bronze Medal"，可應付輸入的長度小於 3 的情況。
    char** rankingMap = NULL;
    if(numsSize < 3){
        rankingMap = (char**)calloc(3, sizeof(char**));
    }else{
        rankingMap = (char**)calloc(numsSize, sizeof(char**));
    }
    rankingMap[0] = goldMedal;
    rankingMap[1] = silverMedal;
    rankingMap[2] = bronzeMedal;
    for(int i = 3; i < numsSize; i++){
        rankingMap[i] = (char*)calloc(6, sizeof(char));
        sprintf(rankingMap[i], "%d", (i+1));
    }    
    
    // 從第 n 名開始，找出第 n 名原本的位置(index)，再找出第 n 名的名次名稱(ranking)。
    // 最後放進結果中(results)。
    char** results = (char**)calloc(numsSize, sizeof(char*));
    for(int i = 0; i < numsSize; i++){
        int index = positions[i];
        char* ranking = rankingMap[i];
        results[index] = ranking;
    }
    
    // 設定回傳陣列的大小。
    *returnSize = numsSize;
    return results;
}